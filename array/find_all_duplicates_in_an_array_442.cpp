
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
//https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            // same mark by negation as a lot of people use, if you ever come across a value that is positive after negating if you know you've seen it before!
            nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0){
                res.push_back(abs(nums[i]));
            }
        }
        return res;
    }

};


int main() {

}