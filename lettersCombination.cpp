//
// Created by asus on 5/11/2020.
//

#include "lettersCombination.h"

void lettersCombination::backTrack(string combination, string letters) {
    // if there is no more digits to check
    if (letters.empty())
        res.push_back(combination); // combinations done
    else {
        // if there are still digits to check
        string digit = letters.substr(0, 1);
        int keyLettersLength = keyPhone[digit].size();
        for (int i = 0; i < keyLettersLength; i++) {
            string dgt = keyPhone[digit].substr(i, 1);
            backTrack(combination + dgt, letters.substr(1));
        }
    }
}

vector<string> lettersCombination::letterCombinations(string digits) {
    if (digits.empty())
        return res;
    this->backTrack("", digits);
    return res;
}
