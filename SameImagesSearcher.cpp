//
// Created by fedor on 03.06.16.
//

#include <opencv2/opencv.hpp>
#include "SameImagesSearcher.h"
#include "FileAgent.h"
#include "MinHash.h"
#include "PointDescriptor.h"
#include "ImageInfo.h"
#include "ImageComparator.h"

using namespace cv;

void SameImagesSearcher::searchSameImages(const char *dirName, double threshold, unsigned long numWordsInVocabulary,
                                          int numHashFunctions) {
    FileAgent fileAgent;
    vector<string> imageNames = fileAgent.getNameOfFilesInDir(dirName);
    PointDescriptor pointDescriptor(vocabularyName);
    vector<ImageInfo> imagesInfo;
    MinHash minHash(numHashFunctions,numWordsInVocabulary);
    cout << "search keypints, calculate descriptors, classificate points to get visual words and choose words using minHash" << endl;

    for(int i = 0; i < imageNames.size(); ++i) {
        Mat img = imread(imageNames[i], CV_LOAD_IMAGE_GRAYSCALE);
        vector<int> words = pointDescriptor.getDescription(img);
        vector<int> chosenWords = minHash.chooseWords(words);
        imagesInfo.push_back(ImageInfo(imageNames[i], chosenWords));
        if(i != 0) {
            cout << (double)i / (double)imageNames.size() * 100 << "% processed" << endl;
        }
    }

    for(int i = 0; i < imagesInfo.size(); ++i) {
        for(int j = 0; j < imagesInfo.size(); ++j) {
            if(i == j) {
                continue;
            }
            double similarity = ImageComparator::compare(imagesInfo[i], imagesInfo[j]);
            if(similarity > threshold) {
                cout << similarity << " " << imagesInfo[i].getName() << " " << imagesInfo[j].getName() << endl;
            }
        }
    }
}

SameImagesSearcher::SameImagesSearcher(const char *vocabularyName) {
    this->vocabularyName = vocabularyName;
}
