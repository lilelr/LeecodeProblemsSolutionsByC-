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
//https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106645/C++Java-*-BFSDFS3liner-Clean-Code-With-Explanation
//
//The idea is to use heap indexing:
//
//1
//2         3
//4   5     6   7
//8 9 x 11  x 13 x 15
//Regardless whether these nodes exist:
//
//        Always make the id of left child as parent_id * 2;
//Always make the id of right child as parent_id * 2 + 1;
//So we can just:
//
//Record the id of left most node when first time at each level of the tree during an pre-order run.(you can tell by check the size of the container to hold the first nodes);
//At each node, compare the distance from it the left most node with the current max width;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max = 0;

        queue<pair<TreeNode*, int>> que;
        que.push(pair<TreeNode*, int>(root,1));
        while (!que.empty()){
            int left = que.front().second, right = left;
            int cur_sz = que.size();
            for(int i=0;i<cur_sz;i++){
                TreeNode* node = que.front().first;
                right = que.front().second;
                que.pop();
                if(node->left){
                    que.push(pair<TreeNode*, int>(node->left, right*2));
                }
                if(node->right){
                    que.push(pair<TreeNode*,int>(node->right, right*2 +1 ));
                }
            }
            max = std::max(max,right+1-left);
        }
        return max;
    }

};

int main() {

}