
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// 判断是否是平衡二叉树，后序遍历
class Solution {
public:
    struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;

        TreeNode(int x) :
                val(x), left(NULL), right(NULL) {
        }
    };

    bool is_balanced(TreeNode *root, int *depth) {
        if (root == NULL) {
            *depth = 0;
            return true;
        }
        int left, right;
        if (is_balanced(root->left, &left) && is_balanced(root->right, &right)) {
            int diff = left - right;
            if (abs(diff) <= 1) {
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }

        return false;
    }

    bool IsBalanced_Solution(TreeNode *pRoot) {
        int depth = 0;
        bool res = is_balanced(pRoot, &depth);
        return res;
    }
};