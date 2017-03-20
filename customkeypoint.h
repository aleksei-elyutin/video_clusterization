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

    int frameNumber; ///Номер кадра, которому принадлежит точка

    bool awake = false; ///Индикатор активности точки в текущий момент

    unsigned int weight = 0; /// "Вес" особой точки



    void incWeight();
    void decWeight();

public:

    void putToSleep();
    void wake();
    bool isAwake();
    void getWeight();

    /**
     * @brief getKeyPoint - Возвращает ОТ
     * @return KeyPoint ОТ
     */

    unsigned int getNumber();
    /**
     * @brief getNumber - Возвращает номер кадра
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
    customKeypoint(KeyPoint& source_keypoint, Mat& source_descriptor, int number);

};


#endif // CUSTOMKEYPOINT_H
