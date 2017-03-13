#ifndef EXTENDEDFRAME_H
#define EXTENDEDFRAME_H

#include <vector>
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
public:
    /** @brief frame Исходное изображение */
    Mat frame;

    /** @brief frame_keypoints Вектор особых точек текущего кадра */
    vector <KeyPoint> frame_keypoints;

    /** @brief frame_descriptors Дескрипторы особых точек текущего кадра */
    Mat frame_descriptors;

    /**
     * @brief extendedFrame Конструктор
     * @param[in] input_frame Исходное изображение
     * @param[in] surf_detector_obj Ссылка на детектор
     */
    extendedFrame(Mat &input_frame, Ptr<xfeatures2d::SURF> &surf_detector_obj);

    /* Геттеры: */

    const Mat &getFrame();
    const Mat &getDescriptors();
    const vector <KeyPoint> &getKeypointVector ();
};

#endif // EXTENDEDFRAME_H
