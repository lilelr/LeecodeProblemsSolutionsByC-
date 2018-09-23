//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<int> m(123, 0);
        vector<int> nums(10, 0);
        for (char c : s)
            m[c]++;
        nums[0] = m['z']; // 找规律， z 字母能唯一代表数字 0
        nums[2] = m['w']; // w 字母能唯一代表数字2
        nums[4] = m['u'];
        nums[6] = m['x'];
        nums[8] = m['g'];
        nums[1] = m['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = m['t'] - nums[2] - nums[8];
        nums[7] = m['s'] - nums[6];
        nums[5] = m['v'] - nums[7];
        nums[9] = m['i'] - nums[5] - nums[6] - nums[8];
        for (int i = 0; i < 10; i++) {
            if (nums[i] > 0) {
                while(nums[i]--) { // 可能会有多个相同数字
                    res += ('0' + i);

                }
            }
        }
        return res;
    }
};


int main() {

}