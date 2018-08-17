//
// Created by YuXiao on 16/4/12.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
#define LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for a binary tree node.
// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *root, vector<int> &ans) {
    if (root != nullptr) {
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
//https://leetcode.com/problems/binary-tree-inorder-traversal/solution/

//Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）
//本文主要解决一个问题，如何实现二叉树的前中后序遍历，有两个要求：
//
//1. O(1)空间复杂度，即只能使用常数空间；
//
//2. 二叉树的形状不能被破坏（中间过程允许改变其形状）。
//
//通常，实现二叉树的前序（preorder）、中序（inorder）、后序（postorder）遍历有两个常用的方法：一是递归(recursive)，二是使用栈实现的迭代版本(stack+iterative)。这两种方法都是O(n)的空间复杂度（递归本身占用stack空间或者用户自定义的stack），所以不满足要求。（用这两种方法实现的中序遍历实现可以参考这里。）
//
//Morris Traversal方法可以做到这两点，与前两种方法的不同在于该方法只需要O(1)空间，而且同样可以在O(n)时间内完成。
//
//要使用O(1)空间进行遍历，最大的难点在于，遍历到子节点的时候怎样重新返回到父节点（假设节点中没有指向父节点的p指针），由于不能用栈作为辅助空间。为了解决这个问题，Morris方法用到了线索二叉树（threaded binary tree）的概念。在Morris方法中不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），只需要利用叶子节点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。
//
//Morris只提供了中序遍历的方法，在中序遍历的基础上稍加修改可以实现前序，而后续就要再费点心思了。所以先从中序开始介绍。
// https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
vector<int> morris_in_order_tranversal(TreeNode* root){
    vector<int> ans;
    if(root== nullptr) return ans;
    TreeNode* cur = root;
    while (cur!= nullptr){
        if(cur->left== nullptr){
            ans.push_back(cur->val);
            cur=cur->right;
        }else{
            TreeNode* predecessor = cur->left;
            while (predecessor->right!= nullptr && predecessor->right!=cur){
                predecessor = predecessor->right;
            }

            if(predecessor->right == nullptr){
                predecessor->right = cur;
                cur = cur->left;
            }

            if(predecessor->right == cur){
                predecessor->right = nullptr;
                ans.push_back(cur->val);
                cur = cur->right;
            }

        }
    }
    return ans;
}
int main() {
    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->left->right = new TreeNode(3);
//    root->right = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
//    preorderTraversal(root);
    vector<int> ans = morris_in_order_tranversal(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

#endif //LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
