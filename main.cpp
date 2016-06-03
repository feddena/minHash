#include <iostream>
#include "opencv2/opencv.hpp"
#include "VocabularyCreator.h"
#include "PointDescriptor.h"

using namespace std;
using namespace cv;

void createVocabulary(const char* resultVocabularyName) {
    VocabularyCreator vocabularyCreator;
    const char* dirName = "/home/fedor/Documents/photoWork/random-photo";
    vocabularyCreator.create(dirName, resultVocabularyName);
}

int main() {
    const char* resultVocabularyName = "dictionary.yml";
    createVocabulary(resultVocabularyName);
//
//    PointDescriptor pointDescriptor(resultVocabularyName);
//    Mat img = imread("/home/fedor/Desktop/3.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//    pointDescriptor.getDescription(img);

}
