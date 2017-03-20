#include "customkeypoint.h"


void customKeypoint::putToSleep()
{
    awake = false;
}

void customKeypoint::wake()
{
    awake = true;
}

const KeyPoint customKeypoint::getKeyPoint()
{
    return keypoint;
}
const Mat customKeypoint::getDescriptor()
{
    return descriptor;
}

void customKeypoint::incWeight()
{
    weight++;
}

void customKeypoint::decWeight()
{
    if (weight > 0) weight--;

}

unsigned int extendedFrame::getNumber()
{
    return frameNumber;
}



customKeypoint::customKeypoint(KeyPoint &source_keypoint, Mat &source_descriptor, int number)
{
    keypoint = source_keypoint;
    descriptor = source_descriptor;
    wake();
    incWeight();
    frameNumber = number;

}
