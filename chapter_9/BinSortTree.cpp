//
// Created by asus on 6/5/2020.
//

#include "BinSortTree.h"

template<class T>
int BinSortTree<T>::num = 0;

template<class T>
BinSortTree<T>::BinSortTree() {
    left_child = nullptr;
    right_child = nullptr;
}

template<class T>
BinSortTree<T>::BinSortTree(T t) {
    value = t;
    left_child = nullptr;
    right_child = nullptr;
}

template<class T>
BinSortTree<T> *BinSortTree<T>::inset_into(BinSortTree<T> *node, T t) {
    if (!node) // node can be insert when it is null
        node = new BinSortTree<T>(t);
    else if (t >= node->value)
        node->right_child = inset_into(node->right_child, t);
    else
        node->left_child = inset_into(node->left_child, t);
    return node;
}

template<class T>
void BinSortTree<T>::creat_tree(T t) {
    value = t;
}

template<class T>
void BinSortTree<T>::in_order_traversal(T *arr) {
    if (this) {
        if (left_child)
            left_child->in_order_traversal(arr);
        arr[num] = this->value;
        num++;
        if (right_child)
            right_child->in_order_traversal(arr);
    }
}


template<class T>
BinSortTree<T>::~BinSortTree() {
    delete left_child;
    delete right_child;
}

#include "iostream"
#include "iomanip"

int main() {
    int num;
    std::cin >> num;
    int temp = num;
    int first;
    std::cin >> first;
    BinSortTree<int> binSortTree(first);
    temp--;
    while (temp--) {
        std::cin >> first;
        binSortTree = *binSortTree.inset_into(&binSortTree, first);
    }
    int *arr = new int[num];
    binSortTree.in_order_traversal(arr);

    // 这是第一题的
    int value1 = num / 2;
    while (arr[value1 - 1] == arr[value1])
        value1--;
    std::cout << arr[num / 2] << " " << num - value1;

    // 这是第二题前K名平均数的
    int K;
    std::cin >> K;
    double average_score = 0;
    for (int i = num - K; i < num; i++)
        average_score += arr[i];
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << average_score / K;
}
