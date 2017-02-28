#include "custom_drawing.hpp"


int customDraw::drawKeypointCircle (Mat& image, KeyPoint& Kpoint, Scalar color)
{

    Point2f point = Kpoint.pt;
    circle( image, point , 4, color , 1, 8, 0 );
    return 1;
}
int customDraw::drawKeypointXmark (Mat& image, KeyPoint& Kpoint, Scalar color)
{
    //Point2f point = Kpoint.pt;
    return 1;
}
int customDraw::drawLineBetweenKeypoints (Mat& image, KeyPoint& Kpoint1, KeyPoint& Kpoint2, Scalar color)
{
    Point2f point1 = Kpoint1.pt;
    Point2f point2 = Kpoint2.pt;
    cv::line( image,point1,point2, color, 1, LINE_8, 0);
    return 1;
}

int customDraw::drawMatches (Mat& image, vector<KeyPoint> kps1, vector<KeyPoint> kps2, vector<DMatch> matches, Scalar color)
{
    vector<Point2f> frame1_matched_points;
    vector<Point2f> frame2_matched_points;


    for( size_t i = 0; i < matches.size(); i++ )
    {
       //previous_frame_matched_features.push_back( previous_frame_keypoints[ matches[i].queryIdx ] );
       frame1_matched_points.push_back( kps1[ matches[i].queryIdx ].pt );
       //current_frame_matched_features.push_back( current_frame_keypoints[ matches[i].trainIdx ] );
       frame2_matched_points.push_back(  kps2[ matches[i].trainIdx ].pt );
    }

    for( size_t i = 0; i < frame1_matched_points.size(); i++ )
    {
      circle(image, frame1_matched_points[i], 4, createColor(custom_colors::COLOR_Blue));
      circle(image, frame2_matched_points[i], 4, createColor(custom_colors::COLOR_Yellow));
      cv::line( image, frame1_matched_points[i], frame2_matched_points[i], color, 1, LINE_8, 0);
    }
}

Scalar customDraw::createColor(uint32_t color)
{
    uint8_t b,g,r;
//    std::cout.unsetf(ios::dec);
//    std::cout.setf(ios::hex);
//    std::cout << "color=" <<  color << std::endl;
    b = color >> 0;
//    std::cout << "b=" <<  (uint16_t)b << std::endl;
    g = color >> 8;
//    std::cout << "g=" << (uint16_t)g << std::endl;
    r = color >> 16;
//    std::cout << "r=" << (uint16_t)r << std::endl;
    Scalar color_scalar(b,g,r);
    return color_scalar;
}


