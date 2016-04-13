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

int minDepthSec(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    } else {
        int leftDepth = minDepthSec(root->left);
        int rightDepth = minDepthSec(root->right);
        if(leftDepth==0){
            return rightDepth+1;
        } else if(rightDepth==0){
            return leftDepth+1;
        } else{
            return min(leftDepth,rightDepth)+1;
        }
    }
}

int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return minDepthSec(root);

}

void hasPathSumSec(TreeNode* root, int sum,bool& flag){
    if(root== nullptr) return;
    sum-=root->val;
   if(root->left == nullptr && root->right == nullptr){
       if(sum==0) flag=true;
   } else{
       hasPathSumSec(root->left,sum,flag);
       hasPathSumSec(root->right,sum,flag);
   }
}

bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return true;
    } else if (root->left == nullptr && root->right == nullptr) {
        return (root->val == sum);
    } else {
        bool flag = false;
        hasPathSumSec(root,sum,flag);
        return flag;
    }
}



int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    TreeNode *third = new TreeNode(3);
    TreeNode *forth = new TreeNode(4);
    TreeNode *fifth = new TreeNode(5);
    root->left = first;
    root->right = second;
//    first->left = third;
//    first->right = forth;
//    third->left = fifth;
    cout << hasPathSum(root,1) << endl;
    return 0;
}
