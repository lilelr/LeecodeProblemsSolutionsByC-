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


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    // 先序遍历
    bool does_tree1_have_tree2(TreeNode *proot1, TreeNode *proot2) {
        if ( proot2 == NULL) {
            return true;
        }

        if (proot1 == NULL ) {
            return false;
        }



        if (proot1->val != proot2->val) {
            return false;
        }
        bool res = does_tree1_have_tree2(proot1->left, proot2->left);
        if (res) {
            res = does_tree1_have_tree2(proot1->right, proot2->right);
        }
        return res;
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        bool result = false;
        if (pRoot1 != NULL && pRoot2 != NULL) {
            result = does_tree1_have_tree2(pRoot1, pRoot2);
            if (!result) {
                result = does_tree1_have_tree2(pRoot1->left, pRoot2);
            }
            if (!result) {
                result = does_tree1_have_tree2(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
};

int main() {

}