
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    // 连续子数组的最大和
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        vector<int> dp(len);
        dp[0] = array[0];

        int ma= dp[0];
        for(int i=1;i<len;i++){
            if(dp[i-1]<= 0){
                dp[i] = array[i];
            }else{
                dp[i] = array[i] + dp[i-1];
            }
            ma = max(ma,dp[i]);
        }

        return ma;
    }
};