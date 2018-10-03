#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.
// 类似单链表有圈问题，找出圈的起点
class Solution {
public:
    int findDuplicate3(vector<int>& nums){
        int n = nums.size();
        if(n > 1){
            int slow = nums[0];
            int fast = nums[nums[0]];

            while (slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            int slow2 = 0;
            while (slow2 != slow){
                slow2 = nums[slow2];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }

};