//
// Created by asus on 5/10/2020.
//

#include "OrthogonalList.h"

OrthogonalList::OrthogonalList(int &verTexNum, int &arcNum) : vertexNum(verTexNum), arcNum(arcNum) {
    this->list = new vertexNode[this->vertexNum];
    this->creatOrthogonalList();
}

OrthogonalList::~OrthogonalList() {
    delete[] (this->list);
}

void OrthogonalList::creatOrthogonalList() {
    for (int i = 0; i < this->vertexNum; ++i) {
        list[i].firstIn = nullptr;
        list[i].firstOut = nullptr;
        list[i].inDegree = list[i].outDegree = 0;
    }   // initialize with null pointer
    for (int j = 0; j < this->arcNum; ++j) {
        int node1, node2;
        std::cin >> node1 >> node2;
        this->insertArcNodeByIndex(node1, node2);
    }
}

int OrthogonalList::getVertexIndexByData(vertexValueType &data) {
    int index;
    for (index = 0; index < this->vertexNum; ++index) {
        if (list[index].data == data)
            return index;
    }
    index = -1;
    return index;
}

void OrthogonalList::insertArcNodeByIndex(int node1, int node2) {
    // new arc node
    auto *newArcNode = new arcNode();
    // tail vertex
    newArcNode->tailVertex = node1;
    // head vertex node
    newArcNode->headVertex = node2;

    // find node1 previous out
    if (list[node1].firstOut) {
        // check out repeat assignment
        arcNode *tmp = list[node1].firstOut;
        while (tmp) {
            if (tmp->headVertex == node2)
                return;
            tmp = tmp->nextTailLink;
        }
        delete (tmp);   // release temporary memory
        newArcNode->nextTailLink = list[node1].firstOut;
    } else
        newArcNode->nextTailLink = nullptr;

    // find node2 previous in
    if (list[node2].firstIn)
        newArcNode->nextHeadLink = list[node2].firstIn;
    else
        newArcNode->nextHeadLink = nullptr;

    // inset new arc node
    list[node1].firstOut = newArcNode;
    // record their out and in degree
    list[node1].outDegree++;
    list[node2].firstIn = newArcNode;
    list[node2].inDegree++;
}

void OrthogonalList::printPopularity() {
    for (int i = 0; i < this->vertexNum; ++i) {
        std::cout << list[i].inDegree - list[i].outDegree << std::endl;
    }
}
