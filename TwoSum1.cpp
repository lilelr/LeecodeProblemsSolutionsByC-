//
// Created by YuXiao on 4/9/16.
//

#include "TwoSum1.h"
#include <vector>
#include <unordered_map>

using namespace std;

//unordered_map
vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++){
        if(m.find(target - nums[i]) != m.end()){
            return {m[target-nums[i],i]};
        }
        m[target-nums[i]] = i;
    }
}

