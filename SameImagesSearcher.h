//
// Created by fedor on 03.06.16.
//

#ifndef MINHASH_SAMEIMAGESSEARCHER_H
#define MINHASH_SAMEIMAGESSEARCHER_H


class SameImagesSearcher {
private:
    const char* resultVocabularyName = "dictionary.yml";
    const int sizeOfDictionary = 100;
public:
    void searchSameImages(const char *dirName);
};


#endif //MINHASH_SAMEIMAGESSEARCHER_H
