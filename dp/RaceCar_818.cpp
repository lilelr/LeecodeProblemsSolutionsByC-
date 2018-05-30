//
// Created by YuXiao on 5/30/18.
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

using namespace std;
// https://leetcode.com/problems/race-car/discuss/123834/C++JavaPython-DP-solution-average-O(logN)
class Solution {
public:
    int dp[10001];

    int racecar(int target) {
        if (dp[target] > 0) {
            return dp[target];
        }
        int n = floor(log2(target)) + 1, res;
        if (1 << n == target + 1) dp[target] = n;
        else {
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n - 1; m++) {
                dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }
        }
        return dp[target];
    }
};


int main() {
        cout<<(1<<0)<<endl;
        cout<<(1<<1)<<endl;
        cout<<floor(log2(2))+1<<endl;
        cout<<ceil(log2(3))<<endl;
}