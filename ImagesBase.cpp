//
// Created by fedor on 10.06.16.
//

#include "ImagesBase.h"
#include "ImageComparator.h"
#include "FileAgent.h"

void ImagesBase::addImage(string name) {
    ImageInfo imageInfo = imageInfoProducer->createSetOfVisualWordsDescription(name);
    bool isContains = false;
    for(int i = 0; i < base.size(); ++i) {
        if(base[i].getWords() == imageInfo.getWords()) {
            isContains = true;
        }
    }
    if(!isContains) {
        base.push_back(imageInfo);
    }
}

ImagesBase::ImagesBase(ImageInfoProducer *imageInfoProducer) {
    this->imageInfoProducer = imageInfoProducer;
}

double ImagesBase::similarity2ImagesInBase(string name) {
    ImageInfo targetImgInfo = imageInfoProducer->createSetOfVisualWordsDescription(name);
    double maximumSimilarity = 0;
    for(int i = 0; i < base.size(); ++i) {
        double similarity = ImageComparator::compare(targetImgInfo, base[i]);
        if(similarity > maximumSimilarity) {
            maximumSimilarity = similarity;
        }
    }
    return maximumSimilarity;
}

void ImagesBase::createBaseFromFolder(const char *dirName, int numFilesFromDir) {
    FileAgent fileAgent;
    vector<string> imgNames = fileAgent.getNameOfFilesInDir(dirName);
    cout << "creating base from folder : " << dirName << endl;
    double processed = 0;
    for(string name : imgNames) {
        addImage(name);
        ++processed;
        if((int)processed % 100 == 0) {
            if(numFilesFromDir == 0) {
                cout << "processed: " << processed / (double) imgNames.size() * 100 << endl;
            } else {
                cout << "processed: " << processed / (double) numFilesFromDir * 100 << endl;
                if(numFilesFromDir == processed) {
                    break;
                }
            }
        }
    }
}
