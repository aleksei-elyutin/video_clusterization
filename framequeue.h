#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H


#include "extendedframe.h"
#include "customkeypoint.h"
#include <deque>
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

    uint32_t number_of_frames = 0; /// Текущее число кадров в очереди

    uint32_t max_frames = 5; /// Максимальное количество кадров в очереди

    uint32_t skip = 0; /// Число пропускаемых кадров

    VideoCapture &src_video_object; /// Ссылка на источник видео

    Ptr<xfeatures2d::SURF> &surf_detector_obj; /// Ссылка на детектор

    FlannBasedMatcher matcher; /// Объект-сопоставитель особых точек

    deque <extendedFrame> main_queue; /// Основная очередь, содержащая исходные кадры и обнаруженные особенности

    list <customKeypoint> table; /// Таблица кастомных ОТ

    deque <vector <DMatch>>  matches_queue; /// Очередь сопоставленных особенностей


     bool allow_back_step = 0; //Разрешение на передвижение очереди назад (будет реализовано позже)

    /* Итераторы */
    deque <extendedFrame>::iterator queue_iterator;




    int match (uint32_t nf1, uint32_t nf2, vector <DMatch> &matches);
    void matchNew (); /* Сопоставляет --- */
    void goodMatches(); /* ФИльтрация сопоставлений */


public:  
    /* Конструкторы */
    FrameQueue(VideoCapture &src, uint32_t max_frames);


    /* Публичные методы*/

    void moveQueue();
        /*Добавляет кадр в конец очереди.
         Удаляет первый кадр из очереди, если очередь заполнена.*/





    int setMaxFrames(uint32_t num);
};

#endif // FRAMEQUEUE_H
