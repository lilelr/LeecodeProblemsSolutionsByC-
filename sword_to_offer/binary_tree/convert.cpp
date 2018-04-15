//
// Created by YuXiao on 4/15/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    void ConvertNode(TreeNode* p_node, TreeNode** p_last_node_in_list){
        if(p_node == nullptr) return;

        TreeNode* p_cur = p_node;
        if(p_cur->left!= nullptr){
            ConvertNode(p_node->left,p_last_node_in_list);
        }

        p_cur ->left = *p_last_node_in_list;
        if(*p_last_node_in_list != nullptr){
            (*p_last_node_in_list)->right = p_cur;
        }

        *p_last_node_in_list = p_cur;

        if(p_cur->right != nullptr){
            ConvertNode(p_cur->right, p_last_node_in_list);
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* plast_node_in_list = nullptr;
        ConvertNode(pRootOfTree,&plast_node_in_list);

        TreeNode* p_head_of_list = plast_node_in_list;
        while (p_head_of_list!= nullptr && p_head_of_list->left != nullptr){
            p_head_of_list = p_head_of_list->left;
        }
        return p_head_of_list;
    }
};


int main() {

}