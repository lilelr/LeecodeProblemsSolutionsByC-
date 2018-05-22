//
// Created by YuXiao on 5/22/18.
//

//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// https://leetcode.com/problems/freedom-trail/description/
// https://leetcode.com/problems/freedom-trail/discuss/98897/Java-Clear-Solution-dfs+memoization
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int r_len = ring.length();
        int k_len = key.length();
        unordered_map<char, unordered_set<int> > mp;
        for (int i = 0; i < r_len; i++) {
            mp[ring[i]].insert(i);
        }

        vector<vector<int>> memo(r_len, vector<int>(k_len, 0));
        return dfs(ring, key, mp, memo, 0, 0) + k_len;
    }

    int dfs(string &ring, string &key, unordered_map<char, unordered_set<int> > &mp,
            vector<vector<int>> &memo, int r_index, int k_index) {
        if (k_index == key.size()) return 0;
        if (memo[r_index][k_index]) return memo[r_index][k_index];
        int ans = INT_MAX;
        for (int next_index : mp[key[k_index]]) {
            int diff = abs(next_index - r_index);
            int step = min(diff, (int) ring.size() - diff);
            ans = min(ans, dfs(ring, key, mp, memo, next_index, k_index + 1) + step);
        }

        memo[r_index][k_index] = ans;
        return ans;
    }
};


int main() {

}