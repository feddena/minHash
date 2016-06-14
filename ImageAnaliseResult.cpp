//
// Created by fedor on 14.06.16.
//

#include "ImageAnaliseResult.h"

double ImageAnaliseResult::getBadProbability() {
    return badProbability;
}

double ImageAnaliseResult::getGoodProbability() {
    return goodProbability;
}

ImageAnaliseResult::ImageAnaliseResult(double badProbability, double goodProbability) {
    this->badProbability = badProbability;
    this->goodProbability = goodProbability;
}
