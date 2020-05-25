//
// Created by asus on 5/25/2020.
//

#ifndef DATASTRUCTHOMEWORKS_TWOSUM_H
#define DATASTRUCTHOMEWORKS_TWOSUM_H

#include "iostream"

class TwoSum {
    int *nums{};
    int *datas{};
    int len{};
    int *res{};
    int target{};
public:
    explicit TwoSum(int N);

    ~TwoSum();

    void readDatas();

    int *twoSum();

    void printRes();
};


#endif //DATASTRUCTHOMEWORKS_TWOSUM_H
