#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H


#include "extendedframe.h"

class FrameQueue
{

uint32_t number_of_frames = 0;
uint32_t max_frames = 5;
FlannBasedMatcher matcher;
public:
    vector <extendedFrame> queue;

    FrameQueue();

    int match (uint32_t nf1, uint32_t nf2, vector <DMatch> &matches);


    int setMaxFrames(uint32_t num);
};

#endif // FRAMEQUEUE_H
