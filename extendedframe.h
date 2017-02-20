#ifndef EXTENDEDFRAME_H
#define EXTENDEDFRAME_H

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

class extendedFrame
{
public:
    Mat frame; // Изображение
    vector <KeyPoint> frame_keypoints; // Вектор особых точек текущего кадра
    Mat frame_descriptors; // Дескрипторы особых точек текущего кадра
    //Преобразовать двумерный массив в вектор одномерных массивов
    //vector <Mat> - необходимо для последующего формирования
    // и быстрого доступа к вектору "сильных" ОТ


    /*Конструкторы*/
    extendedFrame(); //
    extendedFrame(Mat &input, vector<KeyPoint> &keypoints, Mat &descriptors);

    /* Геттеры: */
    const Mat &getFrame();
    const Mat &getDescriptors();
    const vector <KeyPoint> &getKeypointVector ();
};

#endif // EXTENDEDFRAME_H
