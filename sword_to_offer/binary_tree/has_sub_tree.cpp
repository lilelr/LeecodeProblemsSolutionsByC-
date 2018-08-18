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
    /**
     * 判断以根节点为 proot2 的二叉树 是否为 根节点为proot1 的二叉树的部分子树
     * @param proot1
     * @param proot2
     * @return 是/否
     */
    bool does_tree1_have_tree2(TreeNode *proot1, TreeNode *proot2) {
        if ( proot2 == NULL) { // 遍历到proot2 的空节点，返回true
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
            result = does_tree1_have_tree2(pRoot1, pRoot2); // 根节点是否相同
            if (!result) {
                result = does_tree1_have_tree2(pRoot1->left, pRoot2); // pRoot1 的左子树是否等于 以proot2 为根节点的二叉树
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