//
// Created by YuXiao on 16/4/13.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__MINIMUMDEPTHOFBINARYTREE111_H
#define LEECODEPROBLEMSSOLUTIONSBYC__MINIMUMDEPTHOFBINARYTREE111_H
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



int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    TreeNode *third = new TreeNode(3);
    TreeNode *forth = new TreeNode(4);
    TreeNode *fifth = new TreeNode(5);
    root->left = first;
//    root->right = second;
//    first->left = third;
//    first->right = forth;
//    third->left = fifth;
    cout << minDepth(root) << endl;
    return 0;
}
#endif //LEECODEPROBLEMSSOLUTIONSBYC__MINIMUMDEPTHOFBINARYTREE111_H
