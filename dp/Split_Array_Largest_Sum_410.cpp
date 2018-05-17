//
// Created by YuXiao on 5/15/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
//https://leetcode.com/problems/split-array-largest-sum/discuss/89819/C++-Fast-Very-clear-explanation-Clean-Code-Solution-with-Greedy-Algorithm-and-Binary-Search

// https://leetcode.com/problems/split-array-largest-sum/description/
using namespace std;
class Solution {
public:
    bool doable(const vector<int>& nums, int cuts, long long max){
        int acc = 0;
        for(int num : nums){
            if(num > max) return false;
            else if(acc + num <= max) acc+=num;
            else{
                --cuts;
                acc = num;
                if(cuts < 0) return false;
            }
        }
        return true;
    }


    int splitArray(vector<int>& nums, int m) {
            long long left = 0, right = 0;
           for(int num: nums){
               left = max(left, (long long)num);
               right += num;
           }

        while (left < right){
            long long mid = left + (right - left) /2;
            if(doable(nums, m-1, mid)) right = mid;
            else left = mid +1;
        }
        return left;
    }
};