#include "framequeue.h"

FrameQueue::FrameQueue()
{


}

int FrameQueue::match(uint32_t nf1, uint32_t nf2, vector<DMatch> &matches)
{
    if ( ( nf1>this->number_of_frames ) | ( nf2 > this->number_of_frames ) )
    {
        return -1;
    }
    extendedFrame tmp_frame1 = this-> queue.at(nf1);
    extendedFrame tmp_frame2 = this-> queue.at(nf2);
    this->matcher.match(tmp_frame1.getDescriptors(), tmp_frame2.getDescriptors(), matches);
}

int FrameQueue::setMaxFrames(uint32_t num)
{
    if (num>0){
        this->max_frames = num;
        return 1;
    }
    else
        return -1;
}
