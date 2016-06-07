//
// Created by fedor on 03.06.16.
//

#include <opencv2/opencv.hpp>
#include "SameImagesSearcher.h"
#include "FileAgent.h"
#include "MinHash.h"
#include "PointDescriptor.h"

using namespace cv;

void SameImagesSearcher::searchSameImages(const char *dirName) {
    FileAgent fileAgent;
    vector<string> imageNames = fileAgent.getNameOfFilesInDir(dirName);
    PointDescriptor pointDescriptor(resultVocabularyName);
    MinHash minHash(10, sizeOfDictionary);

    for(string imageName : imageNames) {
        Mat img = imread(imageName, CV_LOAD_IMAGE_GRAYSCALE);
        vector<int> words = pointDescriptor.getDescription(img);
        minHash.chooseWords(words);
    }
}
