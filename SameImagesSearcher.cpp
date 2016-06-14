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
#include "ZoneOfInterestChooser.h"
#include "ImageInfoProducer.h"

using namespace cv;

void SameImagesSearcher::searchSameImages(const char *dirName, double threshold, unsigned long numWordsInVocabulary,
                                          int numHashFunctions) {
    FileAgent fileAgent;
    vector<string> imageNames = fileAgent.getNameOfFilesInDir(dirName);
    PointDescriptor pointDescriptor(vocabularyName);
    vector<ImageInfo> imagesInfo;
    MinHash minHash(numHashFunctions,numWordsInVocabulary);
    ImageInfoProducer imageInfoProducer(&minHash, &pointDescriptor);
    cout << "search keypints, calculate descriptors, classificate points to get visual words and choose words using minHash" << endl;
    int prev = 0;
    for(int i = 0; i < imageNames.size(); ++i) {
        ImageInfo imageInfo = imageInfoProducer.createSetOfVisualWordsDescription(imageNames[i]);
        imagesInfo.push_back(imageInfo);
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
