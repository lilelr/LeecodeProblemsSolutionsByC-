/// Copyright 2016 yuXiao

#include "BinaryTreePreorderTraversal144.h"
#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

void preOrder(TreeNode *root,vector<int>& ans) {
    if (root != nullptr) {
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    preOrder(root,ans);

//    for(int i=0;i<ans.size();i++){
//        cout<<ans[i]<<endl;
//    }
    return ans;
}


int main() {
    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->left->right = new TreeNode(3);
//    root->right = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    preorderTraversal(root);
    return 0;
}
