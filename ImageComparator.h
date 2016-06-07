//
// Created by fedor on 07.06.16.
//

#ifndef MINHASH_IMAGECOMPARATOR_H
#define MINHASH_IMAGECOMPARATOR_H


#include "ImageInfo.h"

class ImageComparator {
public:
    static double compare(ImageInfo imageInfo1, ImageInfo imageInfo2);
};


#endif //MINHASH_IMAGECOMPARATOR_H
