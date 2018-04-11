//
// Created by YuXiao on 4/11/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode *pre_in_Create(vector<int> preorder, vector<int> inorder, int s1, int h1, int s2, int h2) {
        TreeNode *root = new TreeNode(preorder[s1]);
        int left_len, right_len;
        int i;
        for (i = s2; inorder[i] != root->val; i++) {}

        left_len = i - s2;
        right_len = h2 - i;
        if (left_len != 0) {
            root->left = pre_in_Create(preorder, inorder, s1 + 1, s1 + left_len, s2, s2 + left_len - 1);
        }
        if (right_len != 0) {
            root->right = pre_in_Create(preorder, inorder, s1 + left_len + 1, h1, i + 1, h2);
        }
        return root;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size() ==0 || vin.size()==0 || pre.size()!=vin.size()) return nullptr;
        TreeNode* root = pre_in_Create(pre,vin,0,pre.size()-1, 0,vin.size()-1);
        return root;
    }
};

int main(){
    vector<int> pre ={1,2,3,4};
    vector<int> vin ={2,1,4,3};
    Solution s;
    TreeNode* root =s.reConstructBinaryTree(pre,vin);
    cout<<root->val<<endl;
    return 0;
}

