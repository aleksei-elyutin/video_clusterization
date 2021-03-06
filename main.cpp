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

int goodFeaturesThresh ( vector<DMatch>& matches, vector<DMatch>& outputGoodMatches, float thresh);


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
    int32_t max_hessian_threshold = 5000, current_hessian_threshold = 2000, _threshold = 20, max__threshold = 100;
    createTrackbar( "Hessian threshold", "Preview window", &current_hessian_threshold, max_hessian_threshold);
    createTrackbar( "Threshold", "Preview window", &_threshold, max__threshold);
    ButtonCallback buttonCallback;
    createButton("Button", buttonCallback );
    /*****************************/

    Ptr<xfeatures2d::SURF> surf_detector_obj; //"умный" указатель на объект класса SURF

    surf_detector_obj = xfeatures2d::SURF::create(
                current_hessian_threshold,
                1, // nOctaves - число октав
                3, // nOctaveLayers - число уровней внутри каждой октавы
                false, // использовать расширенный дескриптор
                true); // не использовать вычисление ориентации);


    vector< DMatch > matches;
    vector< DMatch > good_matches;

    float maxDistance = 0.1;
    while (srcVideo.read(current_ext_frame.frame))
    {
    }


    return 0;
}


int goodFeaturesThresh ( vector<DMatch>& matches, vector<DMatch>& outputGoodMatches, float thresh)
{
    vector<DMatch>::iterator matches_iterator;
    //vector<DMatch> matches_sorted;
    //float thresh = 0.2;
    DMatch current;

    for (matches_iterator = matches.begin(); matches_iterator < matches.end(); matches_iterator++)
    {

       current = *matches_iterator;
      // cout << current.distance << '-';
       if (current.distance < thresh)
       {
           outputGoodMatches.push_back(current);
       //    cout << "y ";
       }
       //else cout << "n ";

    }
   // cout << endl;
    return (int) outputGoodMatches.size();
}


