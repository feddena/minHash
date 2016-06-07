//
// Created by fedor on 01.06.16.
//

#ifndef MINHASH_POINTDESCRIPTOR_H
#define MINHASH_POINTDESCRIPTOR_H

#include "opencv2/opencv.hpp"
#include "opencv2/flann.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"
#include "vector"

using namespace cv;
using namespace std;

class PointDescriptor {
private:
    Mat dictionary;
    Ptr<DescriptorMatcher> matcher = new FlannBasedMatcher;
    Ptr<DescriptorExtractor> pointDetector = cv::FastFeatureDetector::create(20, true, 0);
    Ptr<DescriptorExtractor> descriptorExtractor = xfeatures2d::SIFT::create();
    BOWImgDescriptorExtractor bowDE = BOWImgDescriptorExtractor(descriptorExtractor,matcher);

public:
    PointDescriptor(const char* path2Vocabulary);
    vector<int> getDescription(Mat image);
};


#endif //MINHASH_POINTDESCRIPTOR_H
