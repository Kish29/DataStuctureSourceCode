//
// Created by asus on 5/25/2020.
//

#include "string"
#include "iostream"

using std::string;

#ifndef DATASTRUCTHOMEWORKS_MATCHSTRINGNAME_H
#define DATASTRUCTHOMEWORKS_MATCHSTRINGNAME_H

class MatchStringName {
    // change string to uppercase letter
    const int convertCode = 0b11011111;
    // define loading factor
    const double loadingFactor = 0.75;
    // hash table length
    int hashTabLen{};
    int userNumber{};
    int lgstPrime{};
    string *users{};
    // results
    string *res{};
public:
    explicit MatchStringName(int userNumber);

    ~MatchStringName();

    // convert to uppercase letter
    void convertUpperCase(string &name) const;

    // get hash code, use the largest prime number
    int getLargestPrime();

    int getHashCode(const string &name) const;

    // insert successfully return true, or return false
    bool insertInto(string &key);

    // label each user name
    void labelEachUserName();

    void showResults() const;
};


#endif //DATASTRUCTHOMEWORKS_MATCHSTRINGNAME_H
