//
// Created by asus on 5/12/2020.
//

#include "backTrackDFS.h"

void backTrackDFS::dfs(vector<int> &nums, const int &len, const int &depth, bool *used, vector<int> &path,
                       vector<vector<int>> &res) {
    if (len == depth) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!used[i]) {
            path.push_back(nums[i]);
            used[i] = true;

            dfs(nums, len, depth + 1, used, path, res);
            // 回溯过程
            used[i] = false;
            path.pop_back();
        }
    }
}

vector<vector<int>> backTrackDFS::permute(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> res;
    if (!len)
        return res;

    vector<int> path;
    bool *used = new bool[len]{false};
    dfs(nums, len, 0, used, path, res);
    return res;
}
