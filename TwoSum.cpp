//
// Created by asus on 5/25/2020.
//

#include "TwoSum.h"

TwoSum::TwoSum(int N) : len(N) {
    this->nums = new int[1001];
    this->datas = new int[len];
    this->res = new int[2]{0};
    for (int i = 0; i < 1001; i++) {
        this->nums[i] = -1;
    }
    this->target = 0;
}

TwoSum::~TwoSum() {
    delete[](this->res);
    delete[](this->nums);
    delete[](this->datas);
}

void TwoSum::readDatas() {
    for (int i = 0; i < len; i++) {
        std::cin >> datas[i];
    }
    std::cin >> this->target;
}

int *TwoSum::twoSum() {
    for (int i = 0; i < len; i++) {
        // pay attention to negative number
        if ((target - this->datas[i]) >= 0 && this->nums[target - this->datas[i]] != -1) {
            this->res[0] = this->nums[target - this->datas[i]] + 1;
            this->res[1] = i + 1;
            return res;
        }
        this->nums[datas[i]] = i;
    }
    return nullptr;
}

void TwoSum::printRes() {
    std::cout << res[0] << " " << res[1];
}
