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
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> ar(n + 1);
        for (int i = 0; i < n + 1; i++) {
            ar[i] = i;
        }

        for (vector<int> e:edges) {
            int l = e[0];
            int r = e[1];
            if (find(ar, l) == find(ar, r)) {
                return e;
            } else {
                ar[find(ar, l)] = find(ar, r);
            }
        }
    }

    int find(vector<int> &ar, int l) {
        while (ar[l] != l) {
            l = ar[l];
        }
        return l;
    }
};


//int main() {
//
//}