//
// Created by YuXiao on 5/15/18.

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
// https://leetcode.com/problems/frog-jump/description/
using namespace std;
// https://leetcode.com/problems/frog-jump/discuss/128675/Share-three-c++-solutions
class Solution {
public:
    bool canCross(vector<int> &stones) {
        int n = stones.size(), ans = 0;
        unordered_map<int, set<int>> m;
        for (auto x: stones) m[x] = {};
        m[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (int last_step: m[stones[i]]) {
                for (int next_step = last_step - 1; next_step <= last_step + 1; next_step++) {
                    if (next_step > 0 && m.count(stones[i] + next_step)) {
                        m[stones[i] + next_step].insert(next_step);
                    }
                }
            }
        }
        bool res = !m[stones[n - 1]].empty();
        return res;
    }
};


int main() {

}