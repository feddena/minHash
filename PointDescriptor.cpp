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
static void showPoints(Mat img, vector<KeyPoint> keypoints, vector<KeyPoint> keypointsFiltered) {
    Mat imgKeypoints;// = Mat::zeros(img.size(), img.type());
    //img.copyTo(imgKeypoints);

    drawKeypoints( img, keypointsFiltered, imgKeypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    //-- Show detected (drawn) keypoints
    imshow("KeyPFiltered", imgKeypoints );

    Mat imgKeypoints2;// = Mat::zeros(img.size(), img.type());
    //img.copyTo(imgKeypoints);

    drawKeypoints( img, keypoints, imgKeypoints2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    //-- Show detected (drawn) keypoints
    imshow("Keypoints", imgKeypoints2 );
    waitKey(0);
}
vector<int> PointDescriptor::getDescription(Mat img, Mat zoneOfInterest) {

    //To store the keypoints that will be extracted by SIFT
    std::vector<KeyPoint> keypoints;
    //Detect SIFT keypoints (or feature points)
    pointDetector-> detect(img, keypoints);
    //Filter key points not in zone of interest
    uchar *zonePtr = zoneOfInterest.data;
    std::vector<KeyPoint> keypointsFiltered;
    for (KeyPoint keyPoint : keypoints) {
        if (zonePtr[(int) keyPoint.pt.x + (int) keyPoint.pt.y * img.rows]) {
            keypointsFiltered.push_back(keyPoint);
        }
    }

    //To store the BoW (or BoF) representation of the image
    Mat bowDescriptor;
    std::vector<std::vector<int> >* pointIdxsOfClusters = new vector<vector<int>>();
    for(int i=0; i < dictionary.rows; ++i) {
        pointIdxsOfClusters->push_back(vector<int>());
    }
    //extract BoW (or BoF) descriptor from given image
    bowDE.compute(img, keypointsFiltered, bowDescriptor, pointIdxsOfClusters);

    //showPoints(img, keypoints, keypointsFiltered);

    int threshold = 0;
    std::vector<int> imageClusters;
    for(int i = 0; i < dictionary.rows; ++i) {
        if(pointIdxsOfClusters->at(i).size() > threshold) {
            //cout << i << " " << "cluster : " << i << " numKeyPoints : " << pointIdxsOfClusters->at(i).size() << endl;
            imageClusters.push_back(i);
        }
    }

    return imageClusters;
}