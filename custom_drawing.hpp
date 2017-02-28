#ifndef CUSTOM_DRAWING_HPP
#define CUSTOM_DRAWING_HPP


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "colors.hpp"

using namespace std;
using namespace cv;

class customDraw {
public:
    static int drawKeypointCircle (Mat& image, KeyPoint& Kpoint, Scalar color);

    /*
     * Отрисовывает окружность с центром в точке, соответствующей
     * координатам переданной особой точки.
     * TODO: добавить настройку отображения толщины и размера
    */
    static int drawKeypointXmark (Mat& image, KeyPoint& Kpoint, Scalar color);

    /*
     * Отрисовывает X-метку с центром в точке, соответствующей
     * координатам переданной особой точки.
     * TODO: реализовать!
    */
    static int drawLineBetweenKeypoints (Mat& image, KeyPoint& Kpoint1, KeyPoint& Kpoint2, Scalar color);

    /*
     * Рисует линию между двумя заданными особыми точками
     * TODO: добавить настройку отображения толщины и размера
    */

    static Scalar createColor(uint32_t color);
    /*
     * Генерирует цвет по названию из таблицы цветов в colors.hpp
    */
    static int drawMatches(Mat &image, vector<KeyPoint> kps1, vector<KeyPoint> kps2, vector<DMatch> matches, Scalar color);
};




#endif // CUSTOM_DRAWING_HPP
