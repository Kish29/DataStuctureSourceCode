//
// Created by asus on 5/15/2020.
//

#include "primForMinBinaryTree.h"

primForMinBinaryTree::primForMinBinaryTree(int verNum, int arcNum) : verNum(verNum), arcNum(arcNum) {
    this->graph = new mGraph();
    // vertex list
    this->graph->vertex = new int[verNum];
    // initial two-dimension matrix
    this->graph->adjList = new int *[verNum];
    for (int i = 0; i < verNum; ++i) {
        this->graph->adjList[i] = new int[verNum];
        // assign to INT32_MAX
        for (int j = 0; j < verNum; j++) {
            this->graph->adjList[i][j] = INT32_MAX;
        }
    }
    // get prim minimum binary tree, the number of edge is verNum - 1
    this->primMinBTree = new edge[verNum - 1];
}

primForMinBinaryTree::~primForMinBinaryTree() {
    // release all memory used
    for (int i = 0; i < verNum; ++i) {
        delete[](this->graph->adjList[i]);
    }
    delete[](this->graph->adjList);
    delete[](this->graph);
    delete[](this->primMinBTree);
}

void primForMinBinaryTree::creatAdjList() {
    int node1, node2, edgeWeight;
    for (int i = 0; i < this->arcNum; i++) {
        std::cin >> node1 >> node2 >> edgeWeight;
        this->graph->adjList[node1 - 1][node2 - 1] = edgeWeight;
        this->graph->adjList[node2 - 1][node1 - 1] = edgeWeight;
    }
}

void primForMinBinaryTree::prim() {
    int minIndex, newInsertNode, min, curWeight;
    edge e;
    // create the first edge
    // this circle to get the the indicate (n - 1) edge
    for (int i = 1; i < this->verNum; ++i) {
        this->primMinBTree[i - 1].pre = 0;
        this->primMinBTree[i - 1].end = i;
        this->primMinBTree[i - 1].weight = this->graph->adjList[0][i];
    }
    for (int i = 0; i < this->verNum - 1; i++) {
        min = INT32_MAX;
        // choose the minimum
        for (int k = i; k < this->verNum - 1; k++) {
            if (primMinBTree[k].weight < min) {
                min = primMinBTree[k].weight;
                minIndex = k; // record the minimum index
            }
        }
        e = primMinBTree[minIndex];
        primMinBTree[minIndex] = primMinBTree[i];
        primMinBTree[i] = e;
        newInsertNode = primMinBTree[i].end;
        // update the smaller weight according to the new inserted node
        for (int j = i + 1; j < this->verNum - 1; ++j) {
            curWeight = this->graph->adjList[newInsertNode][primMinBTree[j].end];
            if (curWeight < primMinBTree[j].weight) {
                primMinBTree[j].weight = curWeight;
                primMinBTree[j].pre = newInsertNode;
            }
        }
    }

}

int primForMinBinaryTree::getMaxWeightInPrimTree() {
    int max = this->primMinBTree[0].weight;
    for (int i = 1; i < verNum - 1; ++i) {
        if (this->primMinBTree[i].weight == INT32_MAX)
            return -1;
        if (this->primMinBTree[i].weight > max)
            max = this->primMinBTree[i].weight;
    }
    return max;
}
