#include "extendedframe.h"



extendedFrame::extendedFrame(Mat &input_frame, Ptr<xfeatures2d::SURF> &surf_detector_obj)
{
    frame = input_frame;

    vector <KeyPoint> tmpKPs;
    vector <KeyPoint>::iterator tmpKPs_iterator;
    Mat tmpDsc;

    surf_detector_obj->detectAndCompute(frame, Mat(), tmpKPs, tmpDsc);

    for ( tmpKPs_iterator = tmpKPs.begin(); tmpKPs_iterator < tmpKPs.end(); tmpKPs_iterator++)
    {
        frame_keypoints.push_back(customKeypoint(tmpKPs_iterator*, tmpDsc));

    }


    frame_keypoints.push_back()
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
