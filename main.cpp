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
        if (leftDepth == 0) {
            return rightDepth + 1;
        } else if (rightDepth == 0) {
            return leftDepth + 1;
        } else {
            return min(leftDepth, rightDepth) + 1;
        }
    }
}

int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return minDepthSec(root);

}

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
