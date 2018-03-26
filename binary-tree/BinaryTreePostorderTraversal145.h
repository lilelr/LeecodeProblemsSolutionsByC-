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

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

void preOrder(TreeNode *root, vector<int> &ans) {
    if (root != nullptr) {
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
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


vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    stack<TreeNode*> stack;
    TreeNode *p = root;
    TreeNode *r = NULL;
    while (p || !stack.empty()) {
        if (p) {
            stack.push(p);
            p = p->left;
        } else {
            TreeNode *p = stack.top();
            if (p->right && p->right != r) {
                p = p->right;
                stack.push(p);
                p = p->left;
            } else {
                stack.pop();
                ans.push_back(p->val);
                r = p;
                p = NULL;
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
    vector<int> ans = postorderTraversal(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
#endif //LEECODEPROBLEMSSOLUTIONSBYC__BINARYTREEPOSTORDERTRAVERSAL145_H
