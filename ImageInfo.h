//
// Created by fedor on 07.06.16.
//

#ifndef MINHASH_IMAGEINFO_H
#define MINHASH_IMAGEINFO_H

#include <string>
#include "vector"

using namespace std;

class ImageInfo {
private:
    vector<int> words;
    string name;
public:
    ImageInfo(string name, vector<int> words);
    string getName();
    vector<int> getWords();
};


#endif //MINHASH_IMAGEINFO_H
