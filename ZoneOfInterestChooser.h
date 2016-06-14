//
// Created by fedor on 09.06.16.
//

#ifndef MINHASH_ZONEOFINTERESTCHOOSER_H
#define MINHASH_ZONEOFINTERESTCHOOSER_H

#include "opencv2/opencv.hpp";
#include "string"
using namespace cv;
using namespace std;

class ZoneOfInterestChooser {
public:
    static Mat createMaskOfZone(string imgName);
};


#endif //MINHASH_ZONEOFINTERESTCHOOSER_H
