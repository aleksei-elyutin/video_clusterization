#include "framequeue.h"


FrameQueue::FrameQueue(VideoCapture &src, uint32_t max, Ptr<xfeatures2d::SURF> &surf_ptr)
{
    surf_detector_obj = surf_ptr;
    if (max > 1) max_frames = max;
    else max_frames = 2;

    src_video_object = src;


}


void FrameQueue::moveQueue(uint32_t skip)
{
    Mat tmp_frame;
    if (!skip)
    {
        while (skip--){
          src_video_object.read(tmp);
        } //пропуск кадров
    };

    src_video_object.read(tmp);

    extendedFrame tmp_exframe(tmp_frame, surf_detector_obj); //Создание расширенного кадра

    if (number_of_frames < max_frames)
    {
        queue.push_back(tmp_exframe);
        number_of_frames++;
    }
    else
    {
        queue.pop_front();
        queue.push_back(tmp_exframe);
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
