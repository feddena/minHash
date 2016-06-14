//
// Created by fedor on 10.06.16.
//

#ifndef MINHASH_IMAGESBASE_H
#define MINHASH_IMAGESBASE_H

#include "vector"
#include "set"
#include "opencv2/opencv.hpp"
#include "ImageInfoProducer.h"

using namespace cv;
using namespace std;

class ImagesBase {
private:
    vector<ImageInfo> base;
    ImageInfoProducer * imageInfoProducer;
public:
    ImagesBase(ImageInfoProducer *imageInfoProducer);
    void addImage(string name);
    /*
    *  num2Process == 0 for all images from dir
    */
    void createBaseFromFolder(const char *dirName, int numFilesFromDir);
    double similarity2ImagesInBase(string name);
};


#endif //MINHASH_IMAGESBASE_H
