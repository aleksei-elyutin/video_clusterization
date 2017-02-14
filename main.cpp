#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "colors.hpp"
#include "custom_drawing.hpp"
#include "extendedframe.h"
#include "framequeue.h"

using namespace std;
using namespace cv;
//using namespace cv::xfeatures2d;


int main(int argc, char *argv[])
{
    VideoCapture srcVideo;
    srcVideo = VideoCapture(argv[1]);
    if (!srcVideo.isOpened()) {
        cout << "File invalid!" << endl;
        return -1;
    }
    /* Создание окна и трекбаров */
    namedWindow( "Preview window", WINDOW_AUTOSIZE);
    int32_t max_hessian_threshold = 5000, current_hessian_threshold = 2000, _threshold = 1;
    createTrackbar( "Hessian threshold", "Preview window", &current_hessian_threshold, max_hessian_threshold);
    createTrackbar( "Threshold", "Preview window", &_threshold, _threshold);
    /*****************************/

    Ptr<xfeatures2d::SURF> surf_detector_obj; //"умный" указатель на объект класса SURF

    surf_detector_obj = xfeatures2d::SURF::create(
                current_hessian_threshold,
                1, // nOctaves - число октав
                3, // nOctaveLayers - число уровней внутри каждой октавы
                false, // использовать расширенный дескриптор
                true); // не использовать вычисление ориентации);

    FrameQueue localQ;

    localQ.setMaxFrames(5);
    //vector <KeyPoint> tmp_keypoints;
    //Mat tmp_descriptors;
    Mat current_frame;
    extendedFrame current_ext_frame;

    //while (srcVideo.read(current_frame))
    for (int i = 0; i < 5; i++)
    {
        srcVideo.read(current_ext_frame.frame);
        surf_detector_obj->detectAndCompute(current_ext_frame.frame, Mat(), current_ext_frame.frame_keypoints, current_ext_frame.frame_descriptors);
        localQ.queue.push_back(current_ext_frame);

    }

    for (int i = 0; i <localQ.queue.size(); i++ )
    {
        current_ext_frame = localQ.queue.at(i);
        current_frame = current_ext_frame.getFrame();
        imshow( "Preview window",  current_frame);
        if ( cvWaitKey(10000)  == 27 )  break;
    }


    return 0;
}
