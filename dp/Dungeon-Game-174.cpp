//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(m==0 || n==0){
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n));

        dp[m-1][n-1] = dungeon[m-1][n-1] >0 ? 0:dungeon[m-1][n-1];

        for(int i=n-2;i>=0;i--){
            int val = dp[m-1][i+1] + dungeon[m-1][i];
            if(val >= 0){
                dp[m-1][i] = 0;
            }else{
                dp[m-1][i] = val;
            }
        }
        for(int j=m-2;j>=0;j--){
            int val =  dp[j+1][n-1] + dungeon[j][n-1];
            if(val>=0){
                dp[j][n-1]=0;
            }else {
                dp[j][n-1]=val;
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int val = max(dp[i+1][j],dp[i][j+1])+dungeon[i][j];
                if(val>=0){
                    dp[i][j]=0;
                }else{
                    dp[i][j] = val;
                }
            }
        }
        return -dp[0][0]+1;

    }
};


int main() {

}