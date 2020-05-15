//
// Created by asus on 5/15/2020.
//

#ifndef DATASTRUCTHOMEWORKS_BFSFORMINPATH_H
#define DATASTRUCTHOMEWORKS_BFSFORMINPATH_H

#include "vector"
#include "queue"
#include "iostream"

class bfsForMinPath {
    int *isVisited{};
    int curPos{};
    int verNum{}, arcNum{};
    std::vector<int> *vertex{};
    std::queue<int> vertexInBFS{};
public:
    explicit bfsForMinPath(int verNum, int arcNum, int curPos);

    ~bfsForMinPath();

    void getMinPathLenFromCurPosByBFS();

    void creatNodeRelationShip();

    void showMinPath();
};


#endif //DATASTRUCTHOMEWORKS_BFSFORMINPATH_H
