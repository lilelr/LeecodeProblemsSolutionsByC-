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
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109075/Java-solution-Binary-Search
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // Minimum absolute difference
        int low = nums[1] - nums[0];
        for (int i = 1; i < len-1; i++) {
            low = min(low, nums[i + 1] - nums[i]);
        }

        // Maximum absolute difference
        int high = nums[len - 1] - nums[0];
        // Do binary search for k-th absolute difference
        while (low < high) {
            int mid = low + (high - low) / 2;
            int temp_pairs = count_pairs(nums, mid);
            if (temp_pairs < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int count_pairs(vector<int> &nums, int mid) {
        int len = nums.size();
        int res = 0;
        auto it = nums.begin();
        for(;it!=nums.end();it++){
            int temp = *it +  mid;
            int flag_index = upper_bound(it,nums.end(), temp)- it -1;
            res += flag_index;
        }
        return res;
//        for (int i = 0; i < len; i++) {
//            int flag_index = upper_bound(nums.begin()+i, nums.end(), nums[i] + mid);
//            res +=  - i - 1;
//        }
    }
};