//
// Created by YuXiao on 16/4/18.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__HOUSEROBBER198_H
#define LEECODEPROBLEMSSOLUTIONSBYC__HOUSEROBBER198_H
// dynamic programming

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int rob(vector<int>& nums) {
    int len = nums.size();
    if(len==0) return 0;
    if(len==1) return nums[0];
    int dp[len];
    dp[0]=nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2;i<len;i++){
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[len-1];
}
#endif //LEECODEPROBLEMSSOLUTIONSBYC__HOUSEROBBER198_H
