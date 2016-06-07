#include <iostream>
#include "opencv2/opencv.hpp"
#include "VocabularyCreator.h"
#include "PointDescriptor.h"
#include "MinHash.h"
#include "SameImagesSearcher.h"

using namespace std;
using namespace cv;

void createVocabulary(const char *resultVocabularyName, int vocabularySize) {
    VocabularyCreator vocabularyCreator;
    const char *dirName = "/home/fedor/Documents/photoWork/presents";
    vocabularyCreator.create(dirName, resultVocabularyName, vocabularySize);
}

int main() {
    const char* resultVocabularyName = "dictionary.yml";
    const int sizeOfDictionary = 1000;
//    createVocabulary(vocabularyName, sizeOfDictionary);

    SameImagesSearcher sameImagesSearcher(resultVocabularyName, sizeOfDictionary);
    sameImagesSearcher.searchSameImages("/home/fedor/Documents/photoWork/presents2/", 0.4, sizeOfDictionary, 10);

//    PointDescriptor pointDescriptor(vocabularyName);
//    Mat img = imread("/home/fedor/Documents/photoWork/presents2/835364524796.png", CV_LOAD_IMAGE_GRAYSCALE);
//
//    if (img.empty()) {
//        cout << "empty image";
//        return 0;
//    }
//
//    vector<int> words = pointDescriptor.getDescription(img);
//
//    MinHash minHash(10, sizeOfDictionary);
//    vector<int> chosenWords = minHash.chooseWords(words);
//
//    for (int word : chosenWords) {
//        cout << word << " ";
//    }

}
