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
    /**
     *
     * @param nums
     * @param m nums 分成m 个序列
     * @return
     */
    int splitArray(vector<int> &nums, int m) {
        int ma = 0; // 最大的元素
        long sum = 0; // 元素组的和
        for (int num:nums) {
            ma = max(ma, num);

            sum += num;
        }

        if (m == 1) return (int) sum;

        //binary search
        long l = ma;
        long r = sum;
        while (l <= r) { // 二分
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

    /**
     *
     * @param target 子序列目标和的大小
     * @param nums
     * @param m 子序列的个数
     * @return 是否可以拆分成m个序列，使得每个序列的和都小于 target
     */
    bool valid(long target, vector<int> &nums, int m) {
        int cnt = 1; // 序列的个数
        long total = 0; // 计算当前序列和
        for (int num:nums) {
            total += num;
            if (total > target) {
                total = num; // 拆分了一个序列
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
//    vector<int> nums = {7,2,5,10,8};
//    vector<int> nums = {13,1,13,1};
    vector<int> nums = {13,13,1,1};
    Solution s;
    int res = s.splitArray(nums,2);
    cout<<res<<endl;
}

