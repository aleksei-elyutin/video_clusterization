#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H


#include "extendedframe.h"
#include "customkeypoint.h"
#include <queue>
#include <list>
#include <opencv2/videoio.hpp>

/**
 * @brief The FrameQueue class
 *
 * Класс, реализующий очередь расширенных кадров (extendedFrame).
 */
class FrameQueue
{
private:

    uint32_t number_of_frame = 0; /// Порядковый номер последнего полученного кадра

    uint32_t max_frames = 5; /// Максимальное количество кадров в очереди

    uint32_t skip = 0; /// Число пропускаемых кадров

    VideoCapture &src_video_object; /// Ссылка на источник видео

    Ptr<xfeatures2d::SURF> &surf_detector_obj; /// Ссылка на детектор

    FlannBasedMatcher matcher; /// Объект-сопоставитель особых точек

    queue <extendedFrame> main_queue; /// Основная очередь, содержащая исходные кадры и обнаруженные особенности

    list <customKeypoint> table; /// Таблица кастомных ОТ




//   int match (uint32_t nf1, uint32_t nf2, vector <DMatch> &matches);
//    void matchNew (); /* Сопоставляет --- */
//    void goodMatches(); /* ФИльтрация сопоставлений */


public:  
    /**
     * @brief FrameQueue Конструктор
     * @param src Ссылка на источник видео
     * @param max Длина очереди
     * @param surf_ptr Ссылка на "умный указатель" объекта детектора
     */
    FrameQueue(VideoCapture &src, uint32_t max, Ptr<xfeatures2d::SURF> &surf_ptr);


    /* Публичные методы*/

    /**
     * @brief moveQueue
     * @param skip Число пропускаемых кадров
     *
     * Добавляет кадр в конец очереди.
     * Удаляет первый кадр из очереди, если очередь заполнена.
     */
    void moveQueue(unsigned int skip);






    int setMaxFrames(uint32_t num);
};

#endif // FRAMEQUEUE_H
