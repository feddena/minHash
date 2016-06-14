//
// Created by fedor on 10.06.16.
//

#ifndef MINHASH_IMAGEANALISTIC_H
#define MINHASH_IMAGEANALISTIC_H

#include "MinHash.h"
#include "ImageInfoProducer.h"
#include "ImagesBase.h"
#include "ImageAnaliseResult.h"


class ImageAnalistic {
private:
    ImagesBase *goodBase;
    ImagesBase *badBase;
public:
    ImageAnalistic(unsigned long numWordsInVocabulary, int numHashFunctions, const char *vocabularyName,
                   const char *goodImgDir, const char *badImgsDir);
    ImageAnaliseResult getProbability(string imgName);

    /*
     *  num2Process == 0 for all images from dir
     */
    void analiseImagesInDir(const char *dirName, int num2Process);

};


#endif //MINHASH_IMAGEANALISTIC_H
