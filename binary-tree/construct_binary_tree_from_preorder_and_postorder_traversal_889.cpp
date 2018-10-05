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
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/discuss/161268/C++JavaPython-One-Pass-Real-O(N)

//
//I see a lot of solution saying O(N), but actually not.
//If it takes already O(N) time to find left part and right right, it could not be O(N).
//If it is recursive solution, it should use a hashmap to reduce complexity, otherwise in most cases it has at least average O(NlogN).
//
//Here I share my iterative solution.
//We will preorder generate TreeNodes, push them to stack and postorder pop them out.
//
//Loop on pre array and construct node one by one.
//stack save the current path of tree.
//node = new TreeNode(pre[i]), if not left child, add node to the left. otherwise add it to the right.
//If we meet a same value in the pre and post, it means we complete the construction for current subtree. We pop it from stack.
//Complexity:
//        O(N) Time O(N) Space
class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> pre, vector<int> post) {
        vector<TreeNode *> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode *node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]){
                s.pop_back();
                j++;

            }
            if (s.back()->left == NULL) s.back()->left = node;
            else s.back()->right = node;
            s.push_back(node);
        }
        return s[0];


    }
};

int main() {

}