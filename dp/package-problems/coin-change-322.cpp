//
// Created by YuXiao on 3/25/18.
//https://leetcode.com/problems/coin-change/description/
// https://leetcode.com/problems/ones-and-zeroes/discuss/121876/C++-DP-Knapsack-Approach
// 完全背包问题 you have an infinite number of each kind of coin
//
//// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// // 计算满足amount 的最小硬币数量
//Example 1:
//
//Input: coins = [1, 2, 5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
//Example 2:
//
//Input: coins = [2], amount = 3
//Output: -1

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        int len = coins.size();
        if (len <= 0 || amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, INT_MAX);

//        for(int i=0;i<amount;i++){
//            cout<<dp[i]<<endl;
//        }
        for (int i = 0; i < len; i++) {
            if (coins[i] > amount) continue;
            dp[coins[i]] = 1;
        }

//        for(int i=0;i<amount;i++){
//            cout<<dp[i]<<endl;
//        }
        cout << endl;
        for (int k = 1; k <= amount; k++) {
            for (int i = 0; i < len; i++) {
                if (k - coins[i] >= 0 && dp[k - coins[i]] != INT_MAX) {
                    dp[k] = min(dp[k - coins[i]] + 1, dp[k]);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};


int main() {
    Solution solution;
    vector<int> coins{1, 2, 5};
    int result = solution.coinChange(coins, 11);

}