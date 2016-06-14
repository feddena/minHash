//
// Created by fedor on 10.06.16.
//

#include "ImageAnalistic.h"
#include "FileAgent.h"

ImageAnalistic::ImageAnalistic(unsigned long numWordsInVocabulary, int numHashFunctions, const char *vocabularyName,
                                   const char *goodImgDir, const char *badImgsDir) {
    PointDescriptor *pointDescriptor = new PointDescriptor(vocabularyName);
    MinHash *minHash = new MinHash(numHashFunctions,numWordsInVocabulary);
    ImageInfoProducer *imageInfoProducer = new ImageInfoProducer(minHash, pointDescriptor);
    goodBase = new ImagesBase(imageInfoProducer);
    badBase = new ImagesBase(imageInfoProducer);
    goodBase->createBaseFromFolder(goodImgDir, 1000);
    badBase->createBaseFromFolder(badImgsDir, 1000);
}

ImageAnaliseResult ImageAnalistic::getProbability(string imgName) {
    return ImageAnaliseResult(goodBase->similarity2ImagesInBase(imgName), badBase->similarity2ImagesInBase(imgName));
}

void ImageAnalistic::analiseImagesInDir(const char *dirName, int num2Process) {
    FileAgent fileAgent;
    vector<string> filesInDir = fileAgent.getNameOfFilesInDir(dirName);
    int processed = 0, good = 0, bad = 0;
    for(string fileName : filesInDir) {
        ImageAnaliseResult analiseResult = getProbability(fileName);
        cout << fileName << "  bad : " << analiseResult.getBadProbability() <<
                " good : " << analiseResult.getGoodProbability() << endl;
        if(analiseResult.getBadProbability() > analiseResult.getGoodProbability()) {
            ++bad;
        } else {
            ++good;
        }
        ++processed;
        if(num2Process == processed) {
            break;
        }
    }

    cout << "good : " << good << " bad : " << bad << endl;
}
