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

/**
 * 深度优先遍历
 * @param node 根节点
 * @param flag 是否是平衡二叉树
 * @return 二叉树的高度
 */
int getHeightDepth(TreeNode *node, bool &flag) {
    if (node == nullptr) { // 空节点
        return 0;
    } else if (node->left == nullptr && node->right == nullptr) { // 叶子节点
        return 1;
    } else {
        int leftDepth = getHeightDepth(node->left, flag); // 左子树高度
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
