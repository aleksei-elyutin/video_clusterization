#include "extendedframe.h"

extendedFrame::extendedFrame()
{

}


extendedFrame::extendedFrame(Mat &input, vector<KeyPoint> &keypoints, Mat &descriptors)
{
    this->frame = input;
    this->frame_descriptors=descriptors;
    this->frame_keypoints=keypoints;

}


const Mat &extendedFrame::getFrame()
{
    return this->frame;
}

const Mat &extendedFrame::getDescriptors()
{
    return this->frame_descriptors;
}

const vector <KeyPoint> &extendedFrame::getKeypointVector ()
{
     return this->frame_keypoints;
}
