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
    /**
     * @brief drawKeypointCircle Отрисовывает окружность с центром в точке, соответствующей координатам переданной особой точки.
     * @param image[in]
     * @param Kpoint[in]
     * @param color[in]
     * @return

     */
    static int drawKeypointCircle (Mat& image, KeyPoint& Kpoint, Scalar color);

    /**
     * @brief drawKeypointXmark  Отрисовывает X-метку с центром в точке, соответствующей координатам переданной особой точки.
     * @param image
     * @param Kpoint
     * @param color
     * @return
     * @warning не реализован
     */
    static int drawKeypointXmark (Mat& image, KeyPoint& Kpoint, Scalar color);

    /**
     * @brief drawLineBetweenKeypoints Рисует линию между двумя заданными особыми точками
     * @param image
     * @param Kpoint1
     * @param Kpoint2
     * @param color
     * @return
     * @warning TODO: добавить настройку отображения толщины и размера
     */
    static int drawLineBetweenKeypoints (Mat& image, KeyPoint& Kpoint1, KeyPoint& Kpoint2, Scalar color);

    /**
     * @brief createColor Генерирует цвет по названию из таблицы цветов в colors.hpp
     * @param color
     * @return
     */
    static Scalar createColor(uint32_t color);

    /**
     * @brief drawMatches Рисует линию между особыми точками
     * @param image
     * @param kps1
     * @param kps2
     * @param matches
     * @param color
     * @return
     */
    static int drawMatches(Mat &image, vector<KeyPoint> kps1, vector<KeyPoint> kps2, vector<DMatch> matches, Scalar color);
};




#endif // CUSTOM_DRAWING_HPP
