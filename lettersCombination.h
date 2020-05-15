//
// Created by asus on 5/11/2020.
//

#ifndef DATASTRUCTHOMEWORKS_LETTERSCOMBINATION_H
#define DATASTRUCTHOMEWORKS_LETTERSCOMBINATION_H

#include "map"
#include "string"
#include "vector"

using std::vector;
using std::map;
using std::string;


class lettersCombination {
    map<string, string> keyPhone = {
            {"2", "abc"},
            {"3", "def"},
            {"4", "ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"}
    };
    vector<string> res;

    void backTrack(string combination, string letters);

public:
    vector<string> letterCombinations(string digits);
};


#endif //DATASTRUCTHOMEWORKS_LETTERSCOMBINATION_H
