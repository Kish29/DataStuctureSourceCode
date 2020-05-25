// //
// Created by asus on 4/27/2020.
//
#include <iostream>
#include <string>
#include <vector>
#include "OrthogonalList.h"


using std::vector;
using std::string;


class Solution6 {
public:
    static string convert(string s, int numRows) {
        vector<vector<char> > convStr(numRows);
        int flag = 2 * numRows - 2; // get flag
        for (int i = 0; i < s.length();) {
            // assignment vertical
            for (int j = 0; j < numRows; j++) {
                if (i == s.length())
                    break;
                convStr[j].push_back(s[i++]);
            }
            // assignment offset
            int index = numRows - 2;
            for (int k = 0; k < numRows - 2; k++) {
                if (i == s.length())
                    break;
                convStr[index--].push_back(s[i++]);
            }
        }
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (char &p : convStr[i])
                ans += p;
        }
        return ans;
    }
};


// definition for a binary tree node
template<class dataType>
struct treeNode {
    dataType value;
    treeNode *left;
    treeNode *right;
};

class Solution {
public:
    static treeNode<char> *getTree(string pre, string in) {
        if (pre.empty() || in.empty())  // if tree is empty
            return nullptr;
        auto *node = new treeNode<char>();
        node->value = pre[0];   // get tree by preorder is the root
        int index_for_root;
        for (index_for_root = 0; in[index_for_root] != pre[0]; index_for_root++);
        // get the index of root in inordertravelsal
        node->left = getTree(pre.substr(1, index_for_root), in.substr(0, index_for_root));
        // every recursive set the root node, and return new node for its previous node
        node->right = getTree(pre.substr(index_for_root + 1, pre.length() - (index_for_root + 1)),
                              in.substr(index_for_root + 1, in.length() - (index_for_root + 1)));
        return node;
    }

    //postorderTravelsal
    static void postorderTravelsal(treeNode<char> *root) {
        if (root != nullptr) {
            postorderTravelsal(root->left);
            postorderTravelsal(root->right);
            std::cout << root->value;
        }
    }

    // tree invert
    static treeNode<char> *invertTree(treeNode<char> *root) {
        if (root == nullptr)
            return nullptr;
        auto *node = new treeNode<char>();
        node->value = root->value;
        node->left = invertTree(root->right);
        node->right = invertTree(root->left);
        return node;
    }
};

class Solution2 {
public:
    static treeNode<char> *creatTree(string triple) {
        if (triple.empty())
            return nullptr;
        auto *node = new treeNode<char>();
        // firstly, find root node
        int i_for_node = triple.find_first_of('^', 0);
        if (i_for_node != string::npos) {
            // assignment
            node->value = triple[i_for_node + 1];
            // delete ^ operation
            triple = triple.substr(0, i_for_node) + triple.substr(i_for_node + 3, triple.length());
            // remember to insert 3 in top additionally
            triple = triple.insert(0, 3, ' ');
        } else
            node->value = triple[1];
        // find index for current root node
        i_for_node = triple.find_first_of(node->value, 3);
        while (i_for_node != string::npos) {
            if (triple[i_for_node + 2] == 'L')
                node->left = creatTree(triple.substr(i_for_node, triple.length()));
            if (triple[i_for_node + 2] == 'R')
                node->right = creatTree(triple.substr(i_for_node, triple.length()));
            // find next
            i_for_node = triple.find_first_of(node->value, i_for_node + 1);
        }
        return node;
    }

    // show elements as the format triple
    static void binaryTreeTravelsal(treeNode<char> *root) {
        if (root != nullptr) {
            std::cout << root->value;
            if (root->left != nullptr || root->right != nullptr) {
                std::cout << '(';
                binaryTreeTravelsal(root->left);
                std::cout << ',';
                binaryTreeTravelsal(root->right);
                std::cout << ')';
            }
        }
    }
};


