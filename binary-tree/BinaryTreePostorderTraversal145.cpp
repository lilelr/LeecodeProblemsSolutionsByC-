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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/** 先序遍历
 *
 * @param root 根节点
 * @param ans 先序遍历的结果
 */
void preOrder(TreeNode *root, vector<int> &ans) {
    if (root != nullptr) {
        ans.push_back(root->val);// 先遍历根节点
        preOrder(root->left, ans); // 再遍历左子树
        preOrder(root->right, ans); // 最后遍历右子树
    }
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    preOrder(root, ans);

//    for(int i=0;i<ans.size();i++){
//        cout<<ans[i]<<endl;
//    }
    return ans;
}

/**
 * 后序遍历， 利用栈
 * @param root
 * @return 后序遍历结果
 */
vector<int> postorder_traversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    TreeNode *p = root;
    TreeNode *r = nullptr; // r 标志 访问p之前，访问过的最后一个节点，即p的左节点或右节点
    stack<TreeNode *> stack1;
    while (p || !stack1.empty()) {
        if (p) {
            stack1.push(p);
            p = p->left;// 结合外层的while(p) 一直遍历到树的最左节点
        } else {
            p = stack1.top(); // 弹出当前节点，准备遍历它的右子树
            if (p->right && p->right != r) {
                p = p->right;
                stack1.push(p);
                p = p->left;
            } else {
                ans.push_back(p->val); // 假设只有一个节点p, 那么它的后序遍历，该在什么时候添加它到结果中呢？ 它的左子树（null) ,和右子树（null)都遍历完
                stack1.pop();
                r = p;
                p = nullptr;
            }
        }
    }
    return ans;
}

vector<int> my_post(TreeNode* root){
    vector<int> ans;
    if(root== nullptr) return ans;

    TreeNode* p = root;
    TreeNode* r = nullptr;
    stack<TreeNode *> stack1;
    while (p || !stack1.empty()){
        if(p){
            stack1.push(p);
            p = p->left;
        }else{
            p = stack1.top();
            if(p->right && p->right != r){
                p = p->right;
                stack1.push(p);
                p = p->right;
            }else{
                ans.push_back(p->val);
                stack1.pop();
                r = p;
                p = nullptr;
            }
        }
    }
}



int main() {
    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->left->right = new TreeNode(3);
//    root->right = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
//    preorderTraversal(root);
    vector<int> ans = postorder_traversal(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

#endif //LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
