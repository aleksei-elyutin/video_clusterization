#include "extendedframe.h"



extendedFrame::extendedFrame(Mat &input_frame, Ptr<xfeatures2d::SURF> &surf_detector_obj)
{
    frame = input_frame;
    surf_detector_obj->detectAndCompute(frame, Mat(), frame_keypoints, frame_descriptors);
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
