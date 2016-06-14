//
// Created by fedor on 09.06.16.
//

#include "ZoneOfInterestChooser.h"

Mat ZoneOfInterestChooser::createMaskOfZone(string imgName) {
    Mat img = imread(imgName, -1);
    if(img.channels() == 3) {
        return Mat::ones(img.size(), CV_8UC1);
    }
    vector<Mat> ch;
    split(img, ch);
//    imshow("img", img);
//    imshow("mask", ch[3]); //shows correct mask
    Mat zone;
    ch[3].copyTo(zone);
    Mat kernel = Mat::ones(Size(3,3),CV_8UC1);
    dilate(zone, zone, kernel, Point(1,1), 1);
    erode(zone, zone, kernel, Point(1,1), 10);
//    imshow("zone", zone);
////    waitKey();
    return zone;
}
