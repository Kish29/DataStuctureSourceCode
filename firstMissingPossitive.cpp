//
// Created by asus on 5/26/2020.
//

#include "iostream"

class Solution {
    int *nums{};
    int len{};
public:
    explicit Solution(int N) : len(N) {
        this->nums = new int[len];
    }

    ~Solution() {
        delete this->nums;
    }

    void readDatas() {
        for (int i = 0; i < len; i++)
            std::cin >> nums[i];
    }

    // 原地置换数据的算法，十分精妙，O（n）的时间复杂度，常数的空间复杂度
    int firstMissingPositive() {
        // don't care about negative numbers
        int i, pos;
        // search for 1
        // 因为后面要置1， 所以要提前判断1是否出现
        bool flag = true;
        for (i = 0; i < len; i++)
            if (nums[i] == 1)
                flag = false;
        if (flag)
            return 1;

        // precess array
        // 1. 所有大于数组大小或者小于等于0的数置1
        for (i = 0; i < len; i++)
            if (nums[i] <= 0 || nums[i] > len)
                nums[i] = 1;

        // 2. 将对应位置的数变为相反数
        for (i = 0; i < len; i++) {
            pos = nums[i] > 0 ? nums[i] : (-nums[i]);
            nums[pos - 1] = nums[pos - 1] > 0 ? (-nums[pos - 1]) : nums[pos - 1];
        }

        // find the first number which is possitive
        for (i = 0; i < len; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        // retuen len + 1 by default
        return len + 1;
    }
};

int main() {
    int N;
    std::cin >> N;
    Solution s(N);
    s.readDatas();
    std::cout << s.firstMissingPositive();
}