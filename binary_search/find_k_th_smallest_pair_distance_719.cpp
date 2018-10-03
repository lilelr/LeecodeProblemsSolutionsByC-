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

// general solution
//https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // Minimum absolute difference
        int low = nums[1] - nums[0];
        for (int i = 1; i < len - 1; i++) {
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

    /**
     *
     * @param nums sorted array
     * @param mid difference
     * @return the total amount pairs of nums meeting the requirement that the difference of each pair is less or equal than mid difference
     */
    int count_pairs(vector<int> &nums, int mid) {
        int len = nums.size();
        int res = 0;
        auto it = nums.begin();
        // traversal to  find the total pairs
        for (; it != nums.end(); it++) {
            int temp = *it + mid; // temp represents the element whose value satisfy current value + mid (difference)
            // binary search again to find because nums is sorted
            int flag_index = upper_bound(it, nums.end(), temp) - it - 1;
            res += flag_index;
        }
        return res;

    }
};