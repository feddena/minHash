//
// Created by fedor on 14.06.16.
//

#ifndef MINHASH_IMAGEANALISERESULT_H
#define MINHASH_IMAGEANALISERESULT_H


class ImageAnaliseResult {
private:
    double badProbability;
    double goodProbability;
public:
    ImageAnaliseResult(double badProbability, double goodProbability);
    double getBadProbability();
    double getGoodProbability();
};


#endif //MINHASH_IMAGEANALISERESULT_H
