//
// Created by YuXiao on 4/15/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:

    void find_path(TreeNode *cur, int &expected_sum, int cur_sum, vector<int> &path, vector<vector<int>> &ans) {
        cur_sum += cur->val;
        path.push_back(cur->val); // 添加当前节点的值

        bool is_leaf = false;
        if (cur->left == nullptr && cur->right == nullptr) {
            is_leaf = true;
        }
        if (cur_sum == expected_sum && is_leaf) {
            ans.push_back(path);
        }

        // 先序遍历
        if (cur->left != nullptr) {
            // 访问左子树
            find_path(cur->left, expected_sum, cur_sum, path, ans);
        }
        // 访问右子树
        if (cur->right != nullptr) {
            find_path(cur->right, expected_sum, cur_sum, path, ans);
        }

        path.pop_back(); // 回溯

    }

    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> ans; // 记录结果
        if (root == nullptr) return ans;
        vector<int> path;
        find_path(root, expectNumber, 0, path, ans);
        return ans;
    }
};


int main() {

}