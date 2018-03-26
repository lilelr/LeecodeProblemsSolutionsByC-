//
// Created by YuXiao on 3/26/18.
//
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;
// https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if(nums.size() ==0) return 0;
        unordered_set<int> record(nums.begin(),nums.end());
       int res=1;
        for(int item:nums){
            if(record.find(item)==record.end()) continue;
            record.erase(item);
            int pre = item-1;
            int next = item+1;
            while (record.find(pre)!=record.end()) record.erase(pre--);
            while (record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-pre-1);
        }
        return res;
    }
};