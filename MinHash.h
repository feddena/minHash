//
// Created by fedor on 03.06.16.
//

#ifndef MINHASH_MINHASH_H
#define MINHASH_MINHASH_H

#include "vector"

/* rand number*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class MinHash {
public:

    MinHash(int numHashFunctions, unsigned long numWordsInDictionary);

    /**
     * @return words witch relates to min value according to each hash function
     */
    vector<int> chooseWords(vector<int> &words);

private:
    vector <vector <int> > hashTables;

    void generateTables(int numHashFunctions, unsigned long numWordsInDictionary);

    /**
    * applies min hash function to set of words
    * @return word from set of given words witch relates to minimal value in hash table
    */
    int applyHashFunction(vector<int> hashFunction, vector <int> words);
};


#endif //MINHASH_MINHASH_H
