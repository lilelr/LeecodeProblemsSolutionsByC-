//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len<=1) return true;
        int reachable =0;
        for(int i=0;i<len;i++){
            if(reachable>= (len-1)) return true;
            if(i> reachable) return false;
            reachable = max(reachable,i+nums[i]);
        }

    }
};


int main() {

}