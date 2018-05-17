//
// Created by YuXiao on 5/17/18.
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

typedef long long LL;
using namespace std;

// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/92832/C++-Solution-112-ms-time-memory-O(n2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, int>> d(A.size()); // In d[i][diff] I remember how many arithmetic  sequences   length >= 2 (wich ends on A[i] with diff) , we have between A[0] and A[i] (including)
        int res = 0;
        unordered_set<int> s(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i) {   // we update d
            for (int j = 0; j < i; ++j) {      // we try to find pair to A[i]
                long long diff = (long long)A[i] - A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue; // we don't need long long
                int addon = d[j].count(diff) ? d[j][diff] : 0;  // it's how many arithmetic seq with last two:    A[j] and A[i]
                res += addon;
                if (s.count(A[i]+diff)) {   // do we need sequences with beside A[j], A[i] in future?
                    d[i][diff] += addon;  // sequences with length >= 3 with A[j] A[i]
                    d[i][diff]++;  // now sequence A[j] A[i] also need to be computed
                }
            }
        }
        return res;
    }
};