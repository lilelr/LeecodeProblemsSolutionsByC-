//
// Created by YuXiao on 3/25/18.
//

//
// Created by YuXiao on 3/21/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

typedef int* IntArrayPtr;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0){
            return 0;
        }
        int min_price = prices[0];
        int profit =0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] > min_price){
                profit = max(profit,prices[i] - min_price);
            } else{
                min_price = min(min_price,prices[i]);
            }
        }
        return profit;
    }

    int maxProfit_122(vector<int>& prices){
        if(prices.size() <=1 ){
            return 0;
        }
        int sum_profit = 0;
        int last_price = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] > last_price){
                sum_profit += (prices[i] - last_price);
            }
            last_price =  prices[i];
        }
        return sum_profit;

    }

    // 1，6，3，7
    // (1,6) = 5, （3-5）=-2， 7-（3-5） = 9， 即保存了最大的proift
    int maxProfit_123(int k,vector<int>& prices){
        if(prices.size() <2) {
            return 0;
        }
        int trans=k;
        int len = prices.size();
        IntArrayPtr* dp = new IntArrayPtr[trans];
        for(int i=0;i<trans;i++){
            dp[i] = new int[len];
        }
       // memset(dp,0,sizeof(dp));

//        int dp[2][len];
//        for(int i=0;i<2;i++){
//            for(int j=0;j<len;j++)
//                dp[i][j] = 0;
//        }
        for(int i=0;i<trans;i++){
            int min_price = prices[0];
            if(i>=1){
                dp[i][0] = 0;
                for(int j=1;j<len;j++){
//                    cout<<"round 1:"<<endl;

                    min_price = min(min_price, prices[j-1]- dp[i-1][j-1]);
                    dp[i][j] = max(dp[i][j-1],prices[j] - min_price );
                }
            }else{
                for(int j=1;j<len;j++){
                    min_price = min(min_price,prices[j]);
                    dp[0][j] = max(dp[0][j-1],prices[j] - min_price);
//                    cout<<"round 0:"<<endl;
//                    cout<<dp[0][j]<<" ";
//                    cout<<"\n";
                }

            }
        }
        int result = dp[trans-1][len-1];
        return result;

    }

    int maxProfit_all(vector<int> &prices) {
        int n = prices.size();
        int sum = 0;
        for(int i = 1;i < n;i++){
            if(prices[i] > prices[i-1]){
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    //
//    if k >= n/2, we can have transactions any time, it can be solved by O(n).
//
//    else, we can do it in DP.
//
//    use dp[k][i+1] represents, The max profit of using [0,i] data and k transactions.
//
//    So we have:
//
//            dp[k][i+1] = max(dp[k-1][i+1], dp[k][i], max( dp[k-1][j] + prices[i] - prices[j] ))
//
//    = max(dp[k-1][i+1], dp[k][i], prices[i] + max( dp[k-1][j] - prices[j] )) { 0 <= j < i }
//
//    it can be solved by O(kn).
    int maxProfit123_2(int k, vector<int> &prices) {
        int n = prices.size();
        if(k >= n/2){
            return maxProfit_all(prices);
        }
        int dp[2][n+1];
        memset(dp,0,sizeof(dp));
        for(int t = 1; t <= k; t++){
            int cur_max = 0x80000000;
            dp[t%2][0] = 0;
            for(int i = 0; i < n; i++){
                dp[t%2][i+1] = max(dp[(t+1)%2][i+1],max(dp[t%2][i],prices[i] + cur_max));
                cur_max = max(cur_max,dp[(t+1)%2][i] - prices[i]);
            }
        }
        return dp[k%2][n];
    }

};


int main() {
//      vector<int> prices{7,1,5,3,6,4};
//      vector<int> prices{7,6,4,3,1};
//      vector<int> prices{1,5,3,6,4};
      vector<int> prices{7,6,2,1,7};
    Solution solution;
    int profit = solution.maxProfit_123(2,prices);
    cout<<profit<<endl;


    return 0;

}