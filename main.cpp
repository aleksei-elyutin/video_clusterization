#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "colors.hpp"
#include "custom_drawing.hpp"

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
    Ptr<xfeatures2d::SURF> surf_detector_obj; //"умный" указатель на объект класса SURF
    int32_t max_hessian_threshold = 5000, current_hessian_threshold = 2000, _threshold;
    surf_detector_obj = xfeatures2d::SURF::create(
                current_hessian_threshold,
                1, // nOctaves - число октав
                3, // nOctaveLayers - число уровней внутри каждой октавы
                false, // использовать расширенный дескриптор
                true); // не использовать вычисление ориентации);

    namedWindow( "Preview window", WINDOW_AUTOSIZE);
    createTrackbar( "Hessian threshold", "Preview window", &current_hessian_threshold, max_hessian_threshold);
    createTrackbar( "Threshold", "Preview window", &_threshold, _threshold);


    FlannBasedMatcher matcher;
    return 0;
}
