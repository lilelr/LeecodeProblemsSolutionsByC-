#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
// postorder
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // postorder
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }

    TreeNode *lowestCommonAncestor_dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode *, int> depth;
        unordered_map<TreeNode *, TreeNode *> parent;
        dfs(root, NULL, 0, depth, parent);
        if (depth[p] < depth[q]) {
            swap(p, q);
        }
        int diff = depth[p] - depth[q];
        for (int i = 0; i < diff; i++) {
            p = parent[p];
        }

        while (p != q) {
            p = parent[p];
            q = parent[q];
        }
        return p;
    }

    void dfs(TreeNode *node, TreeNode *p, int d, unordered_map<TreeNode *, int> &depth,
             unordered_map<TreeNode *, TreeNode *> &parent) {
        if (!node) {
            return;
        }
        depth[node] = d;
        parent[node] = p;
        dfs(node->left, node, d + 1, depth, parent);
        dfs(node->right, node, d + 1, depth, parent);
    }
};

int main() {

}