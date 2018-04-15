//
// Created by YuXiao on 16/4/12.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
#define LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *root, vector<int> &ans) {
    if (root != nullptr) {
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
vector<int> morris_in_order_tranversal(TreeNode* root){
    vector<int> ans;
    if(root== nullptr) return ans;
    TreeNode* cur = root;
    while (cur!= nullptr){
        if(cur->left== nullptr){
            ans.push_back(cur->val);
            cur=cur->right;
        }else{
            TreeNode* predecessor = cur->left;
            while (predecessor->right!= nullptr && predecessor->right!=cur){
                predecessor = predecessor->right;
            }

            if(predecessor->right == nullptr){
                predecessor->right = cur;
                cur = cur->left;
            }

            if(predecessor->right == cur){
                predecessor->right = nullptr;
                ans.push_back(cur->val);
                cur = cur->right;
            }

        }
    }
    return ans;
}
int main() {
    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->left->right = new TreeNode(3);
//    root->right = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
//    preorderTraversal(root);
    vector<int> ans = morris_in_order_tranversal(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

#endif //LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
