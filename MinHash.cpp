//
// Created by fedor on 03.06.16.
//

#include <iostream>
#include <values.h>
#include <unistd.h>
#include "MinHash.h"

void MinHash::generateTables(int numHashFunctions, unsigned long numWordsInDictionary)  {
    /* initialize random seed: */
    srand (time(NULL));

    for(int i = 0; i < numHashFunctions; ++i) {
        hashTables.push_back(vector<int>(numWordsInDictionary));
        for(unsigned long j = 0; j < numWordsInDictionary; ++j) {
            hashTables[i][j] = rand();
        }
    }
}

vector<int> MinHash::chooseWords(vector<int> &words) {
    if(words.empty()) {
        return words;
    }

    vector<int> chosenWords;
    for(int i = 0; i < hashTables.size(); ++i) {
        int chosenIdx = applyHashFunction(hashTables[i], words);
        chosenWords.push_back(words[chosenIdx]);
    }
    return chosenWords;
}

int MinHash::applyHashFunction(vector<int> hashFunction, vector<int> words) {
    int minVal = MAXINT, minIdx = 0;
    for(int i = 0; i < words.size(); ++i) {
        int numberRelatedToWord = hashFunction[words[i]];
        if(minVal > numberRelatedToWord) {
            minVal = numberRelatedToWord;
            minIdx = i;
        }
    }
    return minIdx;
}

MinHash::MinHash(int numHashFunctions, unsigned long numWordsInDictionary) {
    generateTables(numHashFunctions, numWordsInDictionary);
}
