//
// Created by fedor on 07.06.16.
//

#include "ImageInfoProducer.h"
#include "ZoneOfInterestChooser.h"

ImageInfo ImageInfoProducer::createSetOfVisualWordsDescription(string imgName) {
    Mat img = imread(imgName, CV_LOAD_IMAGE_GRAYSCALE);
    Mat zoneOfInterest = ZoneOfInterestChooser::createMaskOfZone(imgName);
    vector<int> words = pointDescriptor->getDescription(img, zoneOfInterest);
    vector<int> chosenWords = minHash->chooseWords(words);
    return ImageInfo(imgName, chosenWords);
}

ImageInfoProducer::ImageInfoProducer(MinHash *minHash, PointDescriptor *pointDescriptor) {
    this->minHash = minHash;
    this->pointDescriptor = pointDescriptor;
}
