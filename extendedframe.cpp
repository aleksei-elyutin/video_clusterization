#include "extendedframe.h"

extendedFrame::extendedFrame()
{

}


extendedFrame::extendedFrame(Mat &input, vector<KeyPoint> &keypoints, Mat &descriptors)
{
    frame = input;
    frame_descriptors=descriptors;
    frame_keypoints=keypoints;

}


const Mat &extendedFrame::getFrame()
{
    return frame;
}

const Mat &extendedFrame::getDescriptors()
{
    return frame_descriptors;
}

const vector <KeyPoint> &extendedFrame::getKeypointVector ()
{
     return frame_keypoints;
}
