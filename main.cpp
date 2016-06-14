#include <iostream>
#include "opencv2/opencv.hpp"
#include "VocabularyCreator.h"
#include "PointDescriptor.h"
#include "MinHash.h"
#include "SameImagesSearcher.h"
#include "ImageAnalistic.h"

using namespace std;
using namespace cv;

void createVocabulary(const char *resultVocabularyName, int vocabularySize) {
    VocabularyCreator vocabularyCreator;
    const char *dirName = "/home/fedor/Documents/photoWork/presents";
    vocabularyCreator.create(dirName, resultVocabularyName, vocabularySize);
}

void searchSameImages(const char* resultVocabularyName, int sizeOfDictionary){
    SameImagesSearcher sameImagesSearcher(resultVocabularyName);
    sameImagesSearcher.searchSameImages("/home/fedor/Documents/photoWork/similar_presents/presents2/", 0.5, sizeOfDictionary, 20);

}
int main() {
    const char* vocabularyName = "dictionary.yml";
    const char* goodImagesDirTrain = "/home/fedor/Documents/photoWork/similar_presents/presents_good_base";
    const char* badImagesDirTrain = "/home/fedor/Documents/photoWork/similar_presents/presents_bad_base";
    const char* goodImagesDirTest = "/home/fedor/Documents/photoWork/similar_presents/presents_good_test";
    const char* badImagesDirTest = "/home/fedor/Documents/photoWork/similar_presents/presents_bad_test";
    const int sizeOfDictionary = 1000;
    const int numHashFunctions = 10;


    ImageAnalistic imageAnalistic(sizeOfDictionary, numHashFunctions, vocabularyName, goodImagesDirTrain,
                                  badImagesDirTrain);
    cout << "GOOD : " << endl;
    imageAnalistic.analiseImagesInDir(goodImagesDirTest, 100);
    cout << "BAD : " << endl;
    imageAnalistic.analiseImagesInDir(badImagesDirTest, 100);

}
