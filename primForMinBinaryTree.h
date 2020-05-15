//
// Created by asus on 5/15/2020.
//

#ifndef DATASTRUCTHOMEWORKS_PRIMFORMINBINARYTREE_H
#define DATASTRUCTHOMEWORKS_PRIMFORMINBINARYTREE_H

#include "iostream"

typedef struct {
    int pre, end;
    int weight;
} edge;

typedef struct {
    int *vertex;
    int **adjList;
} mGraph;

class primForMinBinaryTree {
    int verNum{}, arcNum{};
    edge *primMinBTree{};
    mGraph *graph;
public:
    explicit primForMinBinaryTree(int verNum, int arcNum);

    ~primForMinBinaryTree();

    // create adjList
    void creatAdjList();

    void prim();

    int getMaxWeightInPrimTree();
};


#endif //DATASTRUCTHOMEWORKS_PRIMFORMINBINARYTREE_H
