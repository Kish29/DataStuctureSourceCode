//
// Created by asus on 6/5/2020.
//

#ifndef DATASTRUCTHOMEWORKS_BINSORTTREE_H
#define DATASTRUCTHOMEWORKS_BINSORTTREE_H

template<class T>
class BinSortTree {
    static int num;
    T value{};
    BinSortTree *left_child{};
    BinSortTree *right_child{};
public:
    BinSortTree();

    explicit BinSortTree(T t);

    ~BinSortTree();

    BinSortTree *inset_into(BinSortTree<T> *node, T t);

    void creat_tree(T t);

    void in_order_traversal(T *arr);
};


#endif //DATASTRUCTHOMEWORKS_BINSORTTREE_H
