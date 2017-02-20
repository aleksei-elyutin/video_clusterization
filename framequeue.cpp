#include "framequeue.h"

FrameQueue::FrameQueue()
{


}

void FrameQueue::move_queue(extendedFrame &f)
{
    if (number_of_frames < max_frames)
    {
        queue.push_back(f);
        number_of_frames++;
    }
    else
    {
        queue.pop_front();
        queue.push_back(f);
    }

}

int FrameQueue::match(extendedFrame &f1, extendedFrame &f2, vector<DMatch> &matches)
{
   matcher.match (queue.back()->getDescriptors(), queue.back()->getDescriptors() );

}

int FrameQueue::setMaxFrames(uint32_t num)
{
    if (num>0){
        max_frames = num;
        return 1;
    }
    else
        return -1;
}
