//
// Created by YuXiao on 6/2/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
// Union Find
// https://leetcode.com/problems/redundant-connection/description/

// https://leetcode.com/problems/redundant-connection-ii/discuss/108045/C++Java-Union-Find-with-explanation-O(n)
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), canA, canB;
        // step 1 check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                canA = {parent[edge[1]], edge[1]};
                canB = edge;
                edge[1] = 0; // edge[1] is the node with two parents, we tag it with 0
            }
        }

        // step 2 union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // now every node has only one parent, so root of v is implicitly v
            if (pu == v) {
                if (canA.empty()) return edge;
                return canA;
            }
            parent[v] = pu;
        }

        return canB;
    }

private:
    int root(vector<int> &parent, int k) {
        while (parent[k] != k) {
            k = parent[k];
        }
        return k;
    }
};