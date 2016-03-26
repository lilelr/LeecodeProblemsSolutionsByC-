//
// Created by YuXiao on 3/26/16.
//

#ifndef LEECODPROJECT_NINETYEIGHT_H
#define LEECODPROJECT_NINETYEIGHT_H
#include <stdio.h>
#include <iostream>
using namespace std;



//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrder(TreeNode* root, TreeNode*& pre,bool& flag,bool& ans){
    if (root!=NULL) {
        inOrder(root->left,pre,flag,ans);
        if (flag) {
            flag=false;
        }else{
            if (root->val <= pre->val && flag==false) {
                ans=false;
                return;
            }
            pre=root;
        }

        cout<<pre->val<<endl;
        inOrder(root->right,pre,flag,ans);
    }
}

bool isValidBST(TreeNode* root) {
    if (root == NULL || (root->left==NULL && root->right==NULL)) {
        return true;
    }else{
        bool ans=true;
        bool flag=true;
        TreeNode* pre;
        TreeNode* b=root;
        while (b->left != NULL) {
            b=b->left;
        }
        pre=b;
        inOrder(root, pre, flag, ans);
        return ans;
    }
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    TreeNode* firstleft = new TreeNode(14);
    root->left = firstleft;
    root->right = NULL;
    root->left->left=new TreeNode(1);
    cout<<isValidBST(root)<<endl;
    return 0;
}
#endif //LEECODPROJECT_NINETYEIGHT_H
