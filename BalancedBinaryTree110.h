//
// Created by YuXiao on 16/4/13.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__BALANCEDBINARYTREE110_H
#define LEECODEPROBLEMSSOLUTIONSBYC__BALANCEDBINARYTREE110_H
/// Given a binary tree, determine if it is a Balanced Binary Tree.

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

int getHeightDepth(TreeNode *node, bool &flag) {
    if (node == nullptr) {
        return 0;
    } else if (node->left == nullptr && node->right == nullptr) {
        return 1;
    } else {
        int leftDepth = getHeightDepth(node->left, flag);
        int rightDepth = getHeightDepth(node->right, flag);
        if (abs(leftDepth - rightDepth) >= 2) flag = false;
        return max(leftDepth, rightDepth) + 1;
    }
}

bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    bool flag = true;
    getHeightDepth(root, flag);
    cout << flag << endl;
    return flag;
}

int main() {
    TreeNode *root = new TreeNode(0);
//    TreeNode *first = new TreeNode(1);
//    TreeNode *second = new TreeNode(2);
//    TreeNode *third = new TreeNode(3);
//    TreeNode *forth = new TreeNode(4);
//    TreeNode *fifth = new TreeNode(5);
//    root->left = first;
//    root->right = second;
//    first->left = third;
//    first->right = forth;
//    third->left = fifth;
    isBalanced(root);
    return 0;
}

#endif //LEECODEPROBLEMSSOLUTIONSBYC__BALANCEDBINARYTREE110_H
