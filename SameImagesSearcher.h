//
// Created by fedor on 03.06.16.
//

#ifndef MINHASH_SAMEIMAGESSEARCHER_H
#define MINHASH_SAMEIMAGESSEARCHER_H

#include "map"

class SameImagesSearcher {
private:
    const char *vocabularyName = "dictionary.yml";
public:
    SameImagesSearcher(const char *vocabularyName);
    void searchSameImages(const char *dirName, double threshold, unsigned long numWordsInVocabulary,
                                              int numHashFunctions);
};


#endif //MINHASH_SAMEIMAGESSEARCHER_H
