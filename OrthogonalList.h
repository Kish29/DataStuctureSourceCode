//
// Created by asus on 5/10/2020.
//

#ifndef DATASTRUCTHOMEWORKS_ORTHOGONALLIST_H
#define DATASTRUCTHOMEWORKS_ORTHOGONALLIST_H

#include <iostream>

// define the data type for vertex
typedef char vertexValueType;

// define the arc node
typedef struct arcNode {
    int tailVertex{}, headVertex{};
    // point to next head and tail link
    struct arcNode *nextHeadLink{}, *nextTailLink{};
} arcNode;

// define the vertex node
typedef struct vertexNode {
    // data is its value type
    vertexValueType data{};
    int outDegree{}, inDegree{};
    arcNode *firstIn{}, *firstOut{};
} vertexNode;

// define the orthogonal struct
class OrthogonalList {
    vertexNode *list;
    int vertexNum, arcNum;
public:
    explicit OrthogonalList(int &verTexNum, int &arcNum);
    ~OrthogonalList();
    void creatOrthogonalList();
    int getVertexIndexByData(vertexValueType &data);
    void insertVertexNodeByIndex(int index);
    void insertArcNodeByIndex(int node1, int node2);
    void deleteVertexNodeByIndex(int index);
    void printPopularity();
};


#endif //DATASTRUCTHOMEWORKS_ORTHOGONALLIST_H
