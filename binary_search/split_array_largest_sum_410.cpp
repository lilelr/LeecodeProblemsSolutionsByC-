//
// Created by YuXiao on 6/7/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/split-array-largest-sum/description/
// https://leetcode.com/problems/split-array-largest-sum/discuss/89817/Clear-Explanation:-8ms-Binary-Search-Java
class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int ma = 0;
        long sum = 0;
        for (int num:nums) {
            ma = max(ma, num);
            sum += num;
        }

        if (m == 1) return (int) sum;

        //binary search
        long l = ma;
        long r = sum;
        while (l <= r) {
            long mid = (l + r) / 2;
            if (valid(mid, nums, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int res = (int) l;
        return res;
    }

    bool valid(long target, vector<int> &nums, int m) {
        int cnt = 1;
        long total = 0;
        for (int num:nums) {
            total += num;
            if (total > target) {
                total = num;
                cnt++;
                if (cnt > m) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    vector<int> nums = {7,2,5,10,8};
    Solution s;
    int res = s.splitArray(nums,2);
}

