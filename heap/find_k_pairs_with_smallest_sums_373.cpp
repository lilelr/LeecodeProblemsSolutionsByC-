//
// Created by YuXiao on 6/14/18.
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

using namespace std;
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int>::iterator s;
        vector<pair<int, int>> result;
        if (k < 0 || nums1.empty() || nums2.empty()) {
            return result;
        }

        int nums2_size = nums2.size();
        auto comp = [&nums2](pair<int, int> a, pair<int, int> b) {
            return (a.first + nums2[a.second]) > (b.first + nums2[b.second]);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        for (s = nums1.begin(); s != nums1.end(); s++) {
            min_heap.push(make_pair(*s, 0));
        }
        while (k-- > 0 && !min_heap.empty()) {
            auto idx_pair = min_heap.top();
            min_heap.pop();
            result.push_back(make_pair(idx_pair.first, nums2[idx_pair.second]));
            if (idx_pair.second == (nums2_size - 1)) continue;
            else {
                min_heap.push(make_pair(idx_pair.first, idx_pair.second + 1));
            }
        }
        return result;
    }
};