/// Copyright 2016 yuXiao

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

void preOrder(TreeNode *root, TreeNode *&pre, bool isRoot) {
    if (root != nullptr) {

        if (!isRoot) {
            pre->left = root;
            pre = root;
        }

        preOrder(root->left, pre, false);
        preOrder(root->right, pre, false);
    }
}

void flatten(TreeNode *root) {
    if (root != nullptr) {
        TreeNode *pre = root;
        preOrder(root, pre, true);
        TreeNode *secroot = root->left;
        root->right = secroot;
        root->left = nullptr;
        while (secroot != nullptr) {
            secroot->right = secroot->left;
            secroot->left = nullptr;
            secroot = secroot->right;
        }


//        while (root != nullptr) {
//            cout << root->val << endl;
//            root = root->right;
//        }
    }
}

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(4);
    TreeNode *third = new TreeNode(3);
    TreeNode *forth = new TreeNode(4);
    TreeNode *fifth = new TreeNode(5);
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = forth;
    TreeNode *p = root;
    flatten(root);
//    pathSum(root, 4);
//    third->left = fifth;
    return 0;
}
