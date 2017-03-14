#ifndef CUSTOMKEYPOINT_H
#define CUSTOMKEYPOINT_H

#include <opencv2/core.hpp>
#include <vector>
#include <list>

using namespace std;
using namespace cv;

/**
 * @brief The customKeypoint class
 *
 * Объединяет данные об особой точке для организации таблицы состояния очереди
 */
class customKeypoint
{
    KeyPoint keypoint; /// Особая точка

    Mat descriptor; /// Дескриптор точки

    bool awake = false; ///Индикатор активности точки в текущий момент

    unsigned int weight = 0; /// "Вес" особой точки

    unsigned int frameNumber; /// Номер кадра в очереди, к которому принадлежит особая точка

    void incWeight();
    void decWeight();

public:
    /**
     * @brief splitCustomKeypoint - Разделить вектор кастомных ОТ на вектор <KeyPoint> и массив дескрипторов <Mat>
     * @param[in] input_keypoints Входной вектор кастомных ОТ
     * @param[out] output_keypoints Выходной вектор ОТ <KeyPoint>
     * @param[out] output_descriptors Выходной массим дескрипторов
     */
    static void splitCustomKeypoint (vector<customKeypoint> input_keypoints,
                                      vector<KeyPoint>& output_keypoints,
                                      Mat& output_descriptors);

    static void splitCustomKeypoint (list<customKeypoint> input_keypoints,
                                      vector<KeyPoint>& output_keypoints,
                                      Mat& output_descriptors);
    void putToSleep();
    void wake();
    bool isAwake();
    void getWeight();

    /**
     * @brief getKeyPoint - Возвращает ОТ
     * @return KeyPoint ОТ
     */
    const KeyPoint getKeyPoint();
    /**
     * @brief getDescriptor - Возвращает дескриптор
     * @return Mat Дескриптор
     */
    const Mat getDescriptor();

    /**
     * @brief customKeypoint Конструктор
     * @param source_keypoint
     * @param source_descriptor
     */
    customKeypoint(KeyPoint& source_keypoint, Mat& source_descriptor);

};


#endif // CUSTOMKEYPOINT_H
