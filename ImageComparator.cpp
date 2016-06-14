//
// Created by fedor on 07.06.16.
//

#include <set>
#include "ImageComparator.h"

double ImageComparator::compare(ImageInfo imageInfo1, ImageInfo imageInfo2) {
    vector<int> words1 = imageInfo1.getWords();
    vector<int> words2 = imageInfo2.getWords();
    double numEqual = 0;
    set<int> uniqueWords;
    for(int word1 : words1) {
        uniqueWords.insert(word1);
        for(int word2 : words2) {
            uniqueWords.insert(word2);
            if(word1 == word2) {
                ++numEqual;
            }
        }
    } // пересечение на обьединение

    return numEqual / (double)uniqueWords.size();
}
