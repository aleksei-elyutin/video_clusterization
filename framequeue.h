#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H


#include "extendedframe.h"
#include <deque>


class FrameQueue
{
private:
    uint32_t number_of_frames = 0; //текущее число кадров в очереди
    uint32_t max_frames = 5; // Максимальная длина очереди
    FlannBasedMatcher matcher;
    deque <extendedFrame> queue;
    deque <extendedFrame>::iterator queue_iterator;


    void move_queue(extendedFrame &f);
    int match (uint32_t nf1, uint32_t nf2, vector <DMatch> &matches);
    void matchNew (); /* Сопоставляет --- */
    void goodMatches(); /* ФИльтрация сопоставлений */


public:  
    /* Конструкторы */
    FrameQueue();

    /* Публичные методы*/

    void moveQueue(extendedFrame &f);    /*Добавляет кадр в конец очереди.
                                          Удаляет первый кадр из очереди, если очередь заполнена.*/






    int setMaxFrames(uint32_t num);
};

#endif // FRAMEQUEUE_H
