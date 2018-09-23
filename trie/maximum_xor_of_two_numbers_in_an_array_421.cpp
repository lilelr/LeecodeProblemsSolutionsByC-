#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92
using namespace std;

struct TrieNode {
    int val;
    TrieNode *left;
    TrieNode *right;

    TrieNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int findMaximumXOR(vector<int> &nums) {
        TrieNode *root = new TrieNode(0);
        int ans;

        //建树
        TrieNode *cur_node = root;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if (tmp == 0) {
                    if (!cur_node->right) {
                        cur_node->right = new TrieNode(0);
                    }
                    cur_node = cur_node->right;
                } else {
                    if (!cur_node->left) {
                        cur_node->left = new TrieNode(1);
                    }
                    cur_node = cur_node->left;
                }
            }
            cur_node = root;
        }

        //匹配最大异或值

        ans = 0;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if (cur_node->left && cur_node->right) {
                    if (tmp == 0) {
                        cur_node = cur_node->left;
                    } else {
                        cur_node = cur_node->right;
                    }
                } else {
                    cur_node = cur_node->left == NULL ? cur_node->right : cur_node->left;
                }
                res += tmp ^ (cur_node->val << j); // 加上两个数在当前j位的异或值
            }
            cur_node = root;
            ans = max(ans, res);
        }


        return ans;
    }
};