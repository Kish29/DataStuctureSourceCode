//
// Created by asus on 5/12/2020.
//

#ifndef DATASTRUCTHOMEWORKS_BACKTRACKDFS_H
#define DATASTRUCTHOMEWORKS_BACKTRACKDFS_H

#include "vector"

using std::vector;

class backTrackDFS {
    void
    dfs(vector<int> &nums, const int &len, const int &depth, bool *used, vector<int> &path, vector<vector<int> > &res);

public:
    backTrackDFS() = default;
    vector<vector<int>> permute(vector<int> &nums);
};


#endif //DATASTRUCTHOMEWORKS_BACKTRACKDFS_H
