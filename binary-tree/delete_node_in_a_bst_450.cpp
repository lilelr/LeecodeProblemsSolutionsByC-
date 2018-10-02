//https://leetcode.com/problems/delete-node-in-a-bst/description/
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
#define M(a, b) memset(a,b,sizeof(a))

// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
typedef long long LL;

const int maxn = 0x3f3f3f3f;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode *left = root->left;
                delete root;
                return left;
            } else {
                TreeNode *right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

    TreeNode * my_delete(TreeNode* root, int key){
        if(!root) return nullptr;
        if(root->val == key){
            if(!root->right){ // 右子树为空
                TreeNode *left = root->left;
                delete  root;
                return left;
            }else { // 右子树非空，找到右子树的最左边的元素，与根节点交换值
                TreeNode *right = root->right;
                while (right -> left){
                    right = right -> left;
                }
                swap(root->val, right->val);
            }
        }
        root->left = my_delete(root->left, key);
        root->right = my_delete(root->right, key);
    }
};

int main() {

    return 0;
}