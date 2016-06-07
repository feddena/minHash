//
// Created by fedor on 07.06.16.
//

#include "ImageComparator.h"

double ImageComparator::compare(ImageInfo imageInfo1, ImageInfo imageInfo2) {
    vector<int> words1 = imageInfo1.getWords();
    vector<int> words2 = imageInfo2.getWords();
    double numEqual = 0;
    for(int word1 : words1) {
        for(int word2 : words2) {
            if(word1 == word2) {
                ++numEqual;
            }
        }
    }
    return numEqual / ((double)(words2.size() + words1.size())/2);
}
