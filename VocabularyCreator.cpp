//
// Created by fedor on 01.06.16.
//

#include "VocabularyCreator.h"
using namespace cv;
using namespace std;
void VocabularyCreator::create(const char *dirName, const char *pathToResultVocabulary, int dictionarySize) {
    Mat input;
    Mat descriptor;
    vector<KeyPoint> keyPoints;
    Ptr<DescriptorExtractor> pointDetector = cv::FastFeatureDetector::create(10, true, 0);
    Ptr<DescriptorExtractor> descriptorExtractor = xfeatures2d::SIFT::create();
    Mat featuresNotClustered = Mat::zeros(1, descriptorExtractor->descriptorSize(), descriptorExtractor->descriptorType());
    FileAgent fileAgent;
    vector<string> filesInDir = fileAgent.getNameOfFilesInDir(dirName);
    double processed = 0;
    for(string fileName : filesInDir) {
        input = imread(fileName, CV_LOAD_IMAGE_GRAYSCALE); //Load as grayscale
        if(input.empty()) {
            cout << "image is empty - " + fileName << endl;
            continue;
        }

        pointDetector -> detect(input, keyPoints);
        //pointDetector -> detect(input, keyPoints);
        descriptorExtractor -> compute(input, keyPoints, descriptor);
        featuresNotClustered.push_back(descriptor);
        ++processed;
        printf("%f percent done\n", processed * 100 / filesInDir.size());
    }

    TermCriteria tc(CV_TERMCRIT_ITER, 100, 0.001);
    int retries = 1;
    int flags = KMEANS_PP_CENTERS;
    BOWKMeansTrainer bowTrainer(dictionarySize, tc, retries, flags);
    Mat dictionary = bowTrainer.cluster(featuresNotClustered);
    FileStorage fs(pathToResultVocabulary, FileStorage::WRITE);
    fs << "vocabulary" << dictionary;
    fs.release();
}
