#include "customkeypoint.h"


void customKeypoint::putToSleep()
{
    awake = false;
}

void customKeypoint::wake()
{
    awake = true;
}

const KeyPoint customKeypoint::getKeyPoint()
{
    return keypoint;
}
const Mat customKeypoint::getDescriptor()
{
    return descriptor;
}

void customKeypoint::incWeight()
{
    weight++;
}

void customKeypoint::decWeight()
{
    if (weight > 0) weight--;

}

void customKeypoint::splitCustomKeypoint(vector<customKeypoint> input_keypoints, vector<KeyPoint> &output_keypoints, Mat &output_descriptors)
{
    vector<customKeypoint>::iterator ckp_iterator;
    for ( ckp_iterator = input_keypoints.begin(); ckp_iterator < input_keypoints.end(); ckp_iterator++)
    {
        output_keypoints.push_back(ckp_iterator->getKeyPoint());
        output_descriptors.push_back(ckp_iterator->getDescriptor());
    }

}


customKeypoint::customKeypoint(KeyPoint &source_keypoint, Mat &source_descriptor)
{
    keypoint = source_keypoint;
    descriptor = source_descriptor;
    wake();
    incWeight();

}
