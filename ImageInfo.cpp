//
// Created by fedor on 07.06.16.
//

#include "ImageInfo.h"

ImageInfo::ImageInfo(string name, vector<int> words) {
    this->name = name;
    this->words = words;
}

string ImageInfo::getName() {
    return name;
}

vector<int> ImageInfo::getWords() {
    return words;
}
