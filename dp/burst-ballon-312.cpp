
//
// https://leetcode.com/problems/burst-balloons/description/

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int len = nums.size();
        int my_nums[len + 2];
        int n = 1;
        for (int item:nums) {
            if (item > 0) {
                my_nums[n++] = item;
            }
        }
        my_nums[0] = my_nums[n] = 1;
        n++;
        vector<vector<int>> dp(n, vector<int>(n));
        // 至少4个变量，才能完成区间dp遍历
        // k 区间大小
        // 当前遍历的区间 left,right
        // 当前遍历的区间指针 i
        for (int k = 2; k < n; k++) {
            for (int left = 0; left < n - k; left++) {
                int right = left + k;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                                          my_nums[left] * my_nums[i] * my_nums[right] + dp[left][i] + dp[i][right]);
//                    int temp = dp[left][right];
//                    cout<<temp<<endl;
                }
            }
        }




        return dp[0][n - 1];


    }
};


int main() {
    Solution solution;
//        vector<int> balloons{3,1,5,8};
    vector<int> balloons{1, 3, 4};
    int result = solution.maxCoins(balloons);
    cout << result << endl;
    return 0;
}