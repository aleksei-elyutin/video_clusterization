#include "extendedframe.h"



extendedFrame::extendedFrame(Mat &input_frame, vector <KeyPoint>& keypoints, Mat& descriptors, unsigned int number)
{
    frame = input_frame;
    frameNumber = number;

    vector <KeyPoint>::iterator tmpKPs_iterator;

    int r;
    for ( tmpKPs_iterator = keypoints.begin(), r = 0; tmpKPs_iterator < tmpKPs.end(); tmpKPs_iterator++, r++)
    {
        frame_keypoints.push_back(customKeypoint(tmpKPs_iterator*, descriptors.row(r)));
    }
}





void extendedFrame::split(vector<KeyPoint> &output_keypoints, Mat &output_descriptors)
{
    vector<customKeypoint>::iterator ckp_iterator;
    for ( ckp_iterator = frame_keypoints->begin(); ckp_iterator < frame_keypoints->end(); ckp_iterator++)
    {
        output_keypoints.push_back(ckp_iterator->getKeyPoint());
        output_descriptors.push_back(ckp_iterator->getDescriptor());
    }
}


void extendedFrame::splitCustomKeypoints (vector<customKeypoint>& input_keypoints, vector<KeyPoint> &output_keypoints, Mat &output_descriptors)
//статическая версия метода split
{
    vector<customKeypoint>::iterator ckp_iterator;
    for ( ckp_iterator = input_keypoints->begin(); ckp_iterator < input_keypoints->end(); ckp_iterator++)
    {
        output_keypoints.push_back(ckp_iterator->getKeyPoint());
        output_descriptors.push_back(ckp_iterator->getDescriptor());
    }
}

unsigned int extendedFrame::getNumber()
{
    return frameNumber;
}

