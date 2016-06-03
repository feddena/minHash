//
// Created by fedor on 01.06.16.
//

#ifndef MINHASH_FILEAGENT_H
#define MINHASH_FILEAGENT_H

#include <vector>
#include "iostream"
using namespace std;
class FileAgent {
public:
    vector<string> getNameOfFilesInDir(const char* dirName);
};


#endif //MINHASH_FILEAGENT_H
