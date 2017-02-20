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
//#include "framequeue.h"

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

    //FrameQueue localQ;
    FlannBasedMatcher matcher;

    //localQ.setMaxFrames(5);
    //vector <KeyPoint> tmp_keypoints;
    //Mat tmp_descriptors;
    Mat current_frame;
    extendedFrame current_ext_frame, prev_ext_frame;

    vector<extendedFrame> extframes;

    srcVideo.read(prev_ext_frame.frame);
    surf_detector_obj->detectAndCompute(prev_ext_frame.frame, Mat(), prev_ext_frame.frame_keypoints, prev_ext_frame.frame_descriptors);

    while (srcVideo.read(current_ext_frame.frame))
    //for (int i = 0; i < 5; i++)
    {
        surf_detector_obj->detectAndCompute(current_ext_frame.frame, Mat(), current_ext_frame.frame_keypoints, current_ext_frame.frame_descriptors);

        vector< DMatch > matches;

        matcher.match( prev_ext_frame.getDescriptors(), current_ext_frame.getDescriptors(), matches );
        cout << matches.size() << endl;

        prev_ext_frame = current_ext_frame;

        //localQ.queue.push_back(current_ext_frame); // <-- localQ.push_back: добавить в конец вектора queue
        // queue - public to private

    }


   /* for (int i = 1; i <extframes.size(); i++ )
    {

        current_ext_frame = extframes.at(i);
        prev_ext_frame = extframes.at(i-1);

        current_frame = current_ext_frame.getFrame();
        cout << matches.size() << endl;
        imshow( "Preview window",  current_frame);
        if ( cvWaitKey(33)  == 27 )  break;
    }*/


    return 0;
}
