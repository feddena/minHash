//
// Created by fedor on 03.06.16.
//

#include "MinHash.h"

void MinHash::generateTables(int numHashFunctions, unsigned long numWordsInDictionary)  {
    /* initialize random seed: */
    srand (time(NULL));

    for(int i = 0; i < numHashFunctions; ++i) {
        hashTables.push_back(vector<int>(numWordsInDictionary));
        for(unsigned long j = 0; j < numWordsInDictionary; ++j) {
            int rnd = (int)(rand() % numWordsInDictionary);
            hashTables[i].push_back(rnd);
        }
    }
}

vector<int> MinHash::getWordsWithMinHashes(vector<int> &words, int numOfHashFunction) {

}

int MinHash::applyHashFunction(vector<int> weights, vector<int> words) {

    return 0;
}
