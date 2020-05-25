//
// Created by asus on 5/25/2020.
//

#include "MatchStringName.h"
#include "cmath"

MatchStringName::MatchStringName(int N) : userNumber(N) {
    this->hashTabLen = int(this->userNumber / loadingFactor) + 1;
    this->users = new string[hashTabLen];
    for (int i = 0; i < hashTabLen; ++i) {
        users[i] = "#";
    }
    this->res = new string[userNumber];
    this->lgstPrime = this->getLargestPrime();
}

MatchStringName::~MatchStringName() {
    delete[] users;
    delete[] res;
}

void MatchStringName::convertUpperCase(string &name) const {
    if (name.empty())
        return;
    for (char &letter : name) {
        if (0 + letter >= 65 && 0 + letter <= 122)
            letter &= this->convertCode;
    }
}

int MatchStringName::getLargestPrime() {
    int edge;
    int dividor;
    int prime;
    for (prime = hashTabLen - 1; prime; prime--) {
        edge = sqrt(double(abs(prime)));
        for (dividor = 2; dividor <= edge; ++dividor) {
            if (!(prime % dividor))
                break;
        }
        if (dividor >= edge)
            break;
    }
    return prime;
}

int MatchStringName::getHashCode(const string &name) const {
    int hash = 0;
    for (char c : name)
        hash = 31 * hash + c;
    std::cout << abs(hash);
    return abs(hash) % lgstPrime;
}

bool MatchStringName::insertInto(string &key) {
    if (key.empty())
        return false;
    convertUpperCase(key);
    int value = getHashCode(key);
    if (this->users[value] == "#") {
        this->users[value] = key;
        return true;
    } else {
        if (key != this->users[value]) {
            int tmp;
            for (int i = 1; i < hashTabLen; ++i) {
                tmp = (value + i) % this->lgstPrime;
                if (this->users[tmp] == "#") {
                    this->users[tmp] = key;
                    break;
                } else if (this->users[tmp] == key)
                    return false;
            }
        }
        return true;
    }
}

void MatchStringName::labelEachUserName() {
    if (userNumber <= 0)
        return;
    string str;
    for (int i = 0; i < userNumber; ++i) {
        std::cin >> str;
        res[i] = insertInto(str) ? "No" : "Yes";
    }
}

void MatchStringName::showResults() const {
    for (int i = 0; i < userNumber; ++i) {
        std::cout << res[i] << '\n';
    }
}
