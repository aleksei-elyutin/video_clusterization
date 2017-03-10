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

    vector< DMatch > matches;
    vector< DMatch > good_matches;

    float maxDistance = 0.1;
    while (srcVideo.read(current_ext_frame.frame))
    //for (int i = 0; i < 5; i++)
    {
        surf_detector_obj->setHessianThreshold( current_hessian_threshold ); //установка значения порога гессиана
        surf_detector_obj->detectAndCompute(current_ext_frame.frame, Mat(), current_ext_frame.frame_keypoints, current_ext_frame.frame_descriptors);



        matcher.match( prev_ext_frame.getDescriptors(), current_ext_frame.getDescriptors(), matches);

        good_matches.clear();
        cout << goodFeaturesThresh(matches, good_matches, ((float)_threshold)/(float)max__threshold) << endl;



        current_frame = current_ext_frame.getFrame().clone();
        //customDraw::drawMatches(current_frame, prev_ext_frame.getKeypointVector(), current_ext_frame.getKeypointVector(), matches, customDraw::createColor(custom_colors::COLOR_Red));
        customDraw::drawMatches(current_frame, prev_ext_frame.getKeypointVector(), current_ext_frame.getKeypointVector(), good_matches, customDraw::createColor(custom_colors::COLOR_Green));
        imshow( "Preview window",  current_frame);
        if ( cvWaitKey(33)  == 27 )  break;

         prev_ext_frame = current_ext_frame;

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


