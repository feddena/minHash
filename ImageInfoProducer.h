//
// Created by fedor on 07.06.16.
//

#ifndef MINHASH_IMAGEINFOPRODUCER_H
#define MINHASH_IMAGEINFOPRODUCER_H

#include "vector"
#include "set"
#include "opencv2/opencv.hpp"
#include "ImageInfo.h"
#include "MinHash.h"
#include "PointDescriptor.h"

using namespace cv;
using namespace std;

class ImageInfoProducer {
private:
    MinHash *minHash;
    PointDescriptor *pointDescriptor;
public:
    ImageInfoProducer(MinHash *minHash, PointDescriptor *pointDescriptor);
    ImageInfo createSetOfVisualWordsDescription(string imgName);
};


#endif //MINHASH_IMAGEINFOPRODUCER_H
