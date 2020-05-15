//
// Created by asus on 5/15/2020.
//

#include "bfsForMinPath.h"

bfsForMinPath::bfsForMinPath(int verNum, int arcNum, int curPos) : verNum(verNum), arcNum(arcNum), curPos(curPos) {
    this->isVisited = new int[this->verNum];
    // initialise with value -1
    for (int i = 0; i < verNum; ++i) {
        isVisited[i] = -1;
    }
    this->vertex = new std::vector<int>[verNum];
}

bfsForMinPath::~bfsForMinPath() {
    delete[](this->isVisited);
    delete[](this->vertex);
}

void bfsForMinPath::getMinPathLenFromCurPosByBFS() {
    vertexInBFS.push(this->curPos - 1);
    isVisited[this->curPos - 1] = 0;
    while (!vertexInBFS.empty()) {
        // top element quite
        int tmp = vertexInBFS.front();
        // pop the top element
        vertexInBFS.pop();
        int len = vertex[tmp].size();
        for (int i = 0; i < len; ++i) {
            // traversal children for current node
            if (isVisited[vertex[tmp][i]] == -1) {
                vertexInBFS.push(vertex[tmp][i]);
                isVisited[vertex[tmp][i]] = isVisited[tmp] + 1;
            }
        }
    }
}

void bfsForMinPath::creatNodeRelationShip() {
    int node1, node2;
    for (int i = 0; i < this->arcNum; ++i) {
        std::cin >> node1 >> node2;
        // store relationships
        this->vertex[node1 - 1].push_back(node2 - 1);
        this->vertex[node2 - 1].push_back(node1 - 1);
    }
}

void bfsForMinPath::showMinPath() {
    for (int i = 0; i < this->verNum; ++i) {
        std::cout << isVisited[i] << std::endl;
    }
}
