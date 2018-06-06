//
// Created by YuXiao on 6/6/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107293/JavaC++-Simple-dp-solution-with-explanation
using namespace std;

class Solution {
public:

    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size(), res = 0, max_len = 0;
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first == dp[j].first + 1) {
                        dp[i].second += dp[j].second;
                    }
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                }
            }

            if (max_len == dp[i].first) {
                res += dp[i].second;
            }

            if (max_len < dp[i].first) {
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;

    }
};