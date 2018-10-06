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

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        // O(n^2)
        for (int end = 0; end < n; end++) {
            dp[end][end] = 1;
            ++cnt;
            for (int start = 0; start < end; start++) {
                // 动态规划方程
                if (s[start] == s[end] && (start + 1 >= end - 1 || dp[start + 1][end - 1])) {
                    dp[start][end] = 1;
                    ++cnt;
                }
            }
        }
        return cnt;
    }

};

int main() {

}