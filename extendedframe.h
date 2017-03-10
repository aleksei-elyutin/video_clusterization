#ifndef EXTENDEDFRAME_H
#define EXTENDEDFRAME_H

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;

class extendedFrame
{
public:
    Mat frame; // Изображение
    vector <KeyPoint> frame_keypoints; // Вектор особых точек текущего кадра
    Mat frame_descriptors; // Дескрипторы особых точек текущего кадра

    /* Конструкторы */
    extendedFrame(Mat &input_frame, Ptr<xfeatures2d::SURF> &surf_detector_obj);

    /* Геттеры: */
    const Mat &getFrame();
    const Mat &getDescriptors();
    const vector <KeyPoint> &getKeypointVector ();
};

#endif // EXTENDEDFRAME_H
