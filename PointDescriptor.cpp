//
// Created by fedor on 01.06.16.
//

#include "PointDescriptor.h"

PointDescriptor::PointDescriptor(const char* path2Vocabulary) {
    FileStorage fs(path2Vocabulary, FileStorage::READ);
    fs["vocabulary"] >> dictionary;
    fs.release();

    //Set the dictionary with the vocabulary we created in the first step
    bowDE.setVocabulary(dictionary);
}

Mat PointDescriptor::getDescription(Mat img) {

    //To store the keypoints that will be extracted by SIFT
    std::vector<KeyPoint> keypoints;
    //Detect SIFT keypoints (or feature points)
    descriptorExtractor-> detect(img, keypoints);
    //To store the BoW (or BoF) representation of the image
    Mat bowDescriptor;
    std::vector<std::vector<int> >* pointIdxsOfClusters = new vector<vector<int>>();
    for(int i=0; i < dictionary.rows; ++i) {
        pointIdxsOfClusters->push_back(vector<int>());
    }
    //extract BoW (or BoF) descriptor from given image
    bowDE.compute(img, keypoints,bowDescriptor, pointIdxsOfClusters);

    int threshold = 30;
    std::vector<int> imageClusters;
    for(int i = 0; i < dictionary.rows; ++i) {
        if(pointIdxsOfClusters->at(i).size() > threshold) {
            cout << i << " " ; //" cluster : " << i << " numKeyPoints : " << pointIdxsOfClusters->at(i).size() << endl;
            //imageClusters.push_back(i);
        }
    }

    cout << endl;

    return bowDescriptor;
}
