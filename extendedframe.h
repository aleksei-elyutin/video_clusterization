#ifndef EXTENDEDFRAME_H
#define EXTENDEDFRAME_H

#include <vector>
#include "customkeypoint.h"
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;

/**
 * @brief The extendedFrame class
 *
 * Класс "расширенного" кадра, содержащего как само изображение, так и особые точки с дескрипторами
 */
class extendedFrame
{
    Mat frame; /// Исходное изображение

    vector <customKeypoint> frame_keypoints; /// Вектор особых точек текущего кадра

    unsigned int frameNumber; /// Номер кадра

public:  
    /**
     * @brief extendedFrame Конструктор
     * @param[in] input_frame Исходное изображение
     * @param[in] surf_detector_obj Ссылка на детектор
     */
    extendedFrame(Mat &input_frame,
                  vector <KeyPoint>& keypoints,
                  Mat& descriptors,
                  unsigned int number);

    /**
     * @brief splitCustomKeypoints - Разделить вектор кастомных ОТ на вектор <KeyPoint> и массив дескрипторов <Mat>
     * @param[in] input_keypoints Входной вектор кастомных ОТ
     * @param[out] output_keypoints Выходной вектор ОТ <KeyPoint>
     * @param[out] output_descriptors Выходной массив дескрипторов
     */
    static void splitCustomKeypoints (vector<customKeypoint>& input_keypoints,
                                      vector<KeyPoint>& output_keypoints,
                                      Mat& output_descriptors
                                      );
    /**
     * @brief split - Разделить расширенный кадр на вектор <KeyPoint> и массив дескрипторов <Mat>
     * @param[out] output_keypoints Выходной вектор ОТ <KeyPoint>
     * @param[out] output_descriptors Выходной массив дескрипторов
     */
    void split (vector<KeyPoint> &output_keypoints,
                               Mat &output_descriptors);



    const Mat &getFrame();
    unsigned int getNumber();
};

#endif // EXTENDEDFRAME_H
