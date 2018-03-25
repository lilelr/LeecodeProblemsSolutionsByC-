//
// Created by YuXiao on 3/25/18.
//https://leetcode.com/problems/coin-change/description/


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int len = coins.size();
        if(len<=0 || amount<0){
            return -1;
        }
        vector<int> dp(amount+1,INT_MAX);

//        for(int i=0;i<amount;i++){
//            cout<<dp[i]<<endl;
//        }
        for(int i=0;i<len;i++){
            if(coins[i] > amount) continue;
            dp[coins[i]] =1;
        }

//        for(int i=0;i<amount;i++){
//            cout<<dp[i]<<endl;
//        }
        cout<<endl;
        for(int k=1;k<=amount;k++){
            for(int i=0;i< len;i++){
                if(k - coins[i] >= 0 && dp[k-coins[i]] != INT_MAX){
                    dp[k] = min(dp[k-coins[i]]+1,dp[k]);
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};


int main() {
    Solution solution;
    vector<int> coins{1,2,5};
    int result = solution.coinChange(coins,11);

}