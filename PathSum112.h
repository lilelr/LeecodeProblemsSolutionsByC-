//
// Created by YuXiao on 16/4/13.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM112_H
#define LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM112_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

void hasPathSumSec(TreeNode *root, int sum, bool &flag) {
    if (root == nullptr) return;
    sum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
        if (sum == 0) flag = true;
    } else {
        hasPathSumSec(root->left, sum, flag);
        hasPathSumSec(root->right, sum, flag);
    }
}

bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
        return true;
    } else if (root->left == nullptr && root->right == nullptr) {
        return (root->val == sum);
    } else {
        bool flag = false;
        hasPathSumSec(root, sum, flag);
        return flag;
    }
}

#endif //LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM112_H
