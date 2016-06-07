//
// Created by fedor on 01.06.16.
//

#include <dirent.h>
#include "FileAgent.h"

bool isNormalName(struct dirent *ent) {
    return string(ent->d_name).compare(".") && string(ent->d_name).compare("") &&
           string(ent->d_name).compare("..") && ent->d_name != NULL;
}

vector<string> FileAgent::getNameOfFilesInDir(const char* dirName) {
    DIR *dir1;
    struct dirent *ent;
    vector<string> fileNames;
    if ((dir1 = opendir(dirName)) != NULL) {
        while ((ent = readdir(dir1)) != NULL) {
            if (isNormalName(ent)) {
                fileNames.push_back(string(dirName) + "/" + ent->d_name);
            }
        }
    }

    return fileNames;
}

