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

    matchTable(main_queue.back());
}

void FrameQueue::matchTable(extendedFrame newFrame)
{
    vector <KeyPoint> tmp_new_KPs, tmp_table_KPs;
    Mat tmp_new_Dsc, tmp_table_Dsc;
    vector <DMatch> matches;

    vector <customKeypoint> swap;

    double distThresh = 0.2; // Порог расстояния. Перенести!!!

    extendedFrame::splitCustomKeypoints(table,tmp_table_KPs, tmp_table_Dsc);
    newFrame.split(tmp_new_KPs, tmp_new_Dsc);
    matcher_obj.match( tmp_new_Dsc, tmp_table_Dsc, matches);


    for( size_t i = 0; i < tmp_new_KPs.size(); i++ ) // Обновление сопоставленных особенностей
    {
        Mat tmp_single_Dsc(tmp_new_Dsc.row(matches[i].queryIdx));
        customKeypoint tmp_custmKP (tmp_new_KPs[ matches[i].queryIdx ], tmp_single_Dsc, number_of_frame);

        for ( size_t k = 0; k < tmp_table_KPs.size(); k++)
        {
            if ((matches[k].queryIdx == i)&( matches[i].distance <= distThresh * ((double)newFrame.getNumber() - table[matches[i].queryIdx].getNumber() )))
                //если имеется сопоставленная особенность в таблице и расстояние соответствует пороговому
            {
                table[matches[i].trainIdx] = tmp_custmKP;
            }

             else
            {
            swap.push_back(tmp_custmKP);
            }
        }
    }
    for ( size_t i = 0; i<swap.size(); i++)
    {
        table.push_back(swap.at(i));
    }

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

