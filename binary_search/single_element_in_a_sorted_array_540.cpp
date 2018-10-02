#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <list>

//https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100733/Java-Binary-Search-with-Detailed-Explanation
using namespace std;


class Solution {
public:
    // O(n)
//    int singleNonDuplicate(vector<int>& nums) {
//        int ans =0;
//        for(auto& item:nums){
//            ans ^= item;
//        }
//        return ans;
//    }

    // O(logn)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + ((right - left) >>1);
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
            else {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
                else return nums[mid];
            }
        }
        return nums[left];
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,2};
    int ans = s.singleNonDuplicate(nums);
    cout<<ans<<endl;
}