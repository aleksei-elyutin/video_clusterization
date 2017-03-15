#include "framequeue.h"


FrameQueue::FrameQueue(VideoCapture &src, uint32_t max, Ptr<xfeatures2d::SURF> &surf_ptr)
{
    surf_detector_obj = surf_ptr;
    if (max > 1) max_frames = max;
    else max_frames = 2;

    src_video_object = src;

}


void FrameQueue::moveQueue(unsigned int skip)
{
    //Локальные переменные
    Mat tmp_frame;
    vector <KeyPoint> tmp_KPs;
    Mat tmp_Dsc;

    //пропуск кадров
    if (!skip)
    {
        while (skip--){
          src_video_object.read(tmp_frame);
        }
    };

    src_video_object.read(tmp_frame);
    surf_detector_obj->detectAndCompute(tmp_frame, Mat(), tmp_KPs, tmp_Dsc);

    // Создаем и пушим расширенный кадр
    if (number_of_frame >= max_frames)
    {
        main_queue.pop();
    }     
    main_queue.push( extendedFrame (tmp_frame,  tmp_KPs,  tmp_Dsc, number_of_frame++));
}


//int FrameQueue::match(extendedFrame &f1, extendedFrame &f2, vector<DMatch> &matches)
//{
//   matcher.match (queue.back()->getDescriptors(), queue.back()->getDescriptors() );

//   //////////////
//   //////////////
//   ////////////////////////////////////////////////////////////////////////////////////////////////
//   ///////////////////////////////  ЛОПАТА              /////////////////////////////////////////////
//   /////////////////////////////////////////////////////////////////////////////////////////////////
//   ///////////////
//   ///////////////

//}

int FrameQueue::setMaxFrames(uint32_t num)
{
    if (num>0){
        max_frames = num;
        return 1;
    }
    else
        return -1;
}

