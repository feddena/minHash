//
// Created by fedor on 01.06.16.
//

#ifndef MINHASH_VOCABULARYCREATOR_H
#define MINHASH_VOCABULARYCREATOR_H

#include "opencv2/opencv.hpp"
#include "opencv2/flann.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"
#include "FileAgent.h"
#include "opencv2/features2d.hpp"

class VocabularyCreator {
public:
    void create(const char *dirName, const char *pathToResultVocabulary, int dictionarySize);
};


#endif //MINHASH_VOCABULARYCREATOR_H
