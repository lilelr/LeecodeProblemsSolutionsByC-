//
// Created by YuXiao on 16/4/13.
// PreOrder or PostOrder
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM113_H
#define LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM113_H
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
void hasPathSumSec(TreeNode *root, int sum, vector<int> answer, int pos, vector<vector<int>> &res) {
    if (root == nullptr) return;
    sum -= root->val;
    answer.reserve(pos+1);
    pos++;
    answer.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        if (sum == 0) {
            vector<int> tmpans;
            for (int i = 0; i < pos; i++) {
                tmpans.push_back(answer[i]);
            }
            res.push_back(tmpans);
        }
    } else {
        hasPathSumSec(root->left, sum, answer, pos, res);
        hasPathSumSec(root->right, sum, answer, pos, res);
    }
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    vector<int> answer;
    int pos = 0;
    hasPathSumSec(root, sum, answer, pos, res);

    for (int i = 0; i < res.size(); i++) {
        vector<int> item = res[i];
//        for(vector<int>::iterator iterator =item.begin();iterator!=item.end();iterator++ ){
//            cout<<*iterator<<endl;
//        }
        for (int i = 0; i < item.size(); i++) {
            cout << item[i] << endl;
        }
    }
    return res;
}

vector<vector<int>> pathSumByPostOrderUsingStack(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    if(root == NULL) return ret;
    vector<int> v;
    stack<TreeNode *> node_stack;
    TreeNode *pre = NULL, *cur = root;
    int SUM = 0;
    while(cur != NULL || !node_stack.empty())
    {
        while(cur)
        {
            node_stack.push(cur);
            SUM += cur->val;
            v.push_back(cur->val);
            cur = cur->left;
        }
        cur = node_stack.top();
        if(cur->left == NULL && cur->right == NULL && SUM == sum)
        {
            ret.push_back(v);
            pre = cur;
            node_stack.pop();
            SUM -= cur->val;
            v.pop_back();
            cur = NULL;
            continue;
        }
        if(cur->right != NULL && pre != cur->right)
        {
            cur = cur->right;
        }
        else
        {
            pre = cur;
            node_stack.pop();
            SUM -= cur->val;
            v.pop_back();
            cur = NULL;
        }
    }
    return ret;
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
    pathSum(root, 4);
//    third->left = fifth;
    return 0;
}
#endif //LEECODEPROBLEMSSOLUTIONSBYC__PATHSUM113_H
