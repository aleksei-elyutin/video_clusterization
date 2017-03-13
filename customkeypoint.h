#ifndef CUSTOMKEYPOINT_H
#define CUSTOMKEYPOINT_H

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class customKeypoint : public KeyPoint
{
    /** @brief descriptor  */
    Mat descriptor;
    /** @brief isAlive */
    bool isAlive = false;
    /** @brief weight */
    unsigned int weight;

public:

    void killPoint ()


    customKeypoint( KeyPoint& source_keypoint,
            );

};


#endif // CUSTOMKEYPOINT_H
