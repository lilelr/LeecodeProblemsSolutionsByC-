//
// Created by YuXiao on 5/24/18.
//https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
// https://leetcode.com/problems/sum-of-distances-in-tree/description/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        vector<unordered_set<int>> tree(N);
        vector<int> res(N, 0);
        vector<int> count(N, 0);
        if (N == 1) return res;

        for (auto e: edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }

        unordered_set<int> seen1, seen2;
        dfs(0, seen1, tree, res, count);
        dfs2(0, seen2, tree, res, count, N);
        return res;
    }

    // post order
    void
    dfs(int root, unordered_set<int> &seen, vector<unordered_set<int>> &tree, vector<int> &res, vector<int> &count) {
        seen.insert(root);
        for (auto i:tree[root]) {
            if (seen.count(i) == 0) {
                dfs(i, seen, tree, res, count);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        }
        count[root] += 1;
    }

    // pre order
    void
    dfs2(int root, unordered_set<int> &seen, vector<unordered_set<int>> &tree, vector<int> &res, vector<int> &count,
         int N) {
        seen.insert(root);
        for (auto i:tree[root]) {
            if (seen.count(i) == 0) {
                res[i] = res[root] - count[i] + N - count[i];
                dfs2(i, seen, tree, res, count, N);
            }
        }
    }
};