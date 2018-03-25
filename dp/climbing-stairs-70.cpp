//
// Created by YuXiao on 3/25/18.
//

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
// https://leetcode.com/problems/climbing-stairs/description/
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n ==1){
            return 1;
        }
        if(n==2){
            return 2;
        }

        int dp[2];
        dp[0]=1; dp[1]=2;
        for(int i=3;i<=n;i++){
            int temp = dp[0];
            dp[0] = dp[1];
            dp[1] = dp[1] + temp;
        }
        return dp[1];


    }
};


int main() {

}