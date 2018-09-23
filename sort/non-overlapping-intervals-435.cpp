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

//https://leetcode.com/problems/non-overlapping-intervals/description/
//  Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};
//
//// Input: [ [1,2], [2,3], [3,4], [1,3] ]
// 排序后变成：[1,2] [2,3] [1,3] [3,4] 第 31 行到35行的排序规则使得重叠区间内 区间长度最小的区间 排在前面 即[2,3] 排在[1,3] 前面
//Output: 1
//
//Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
class Solution {
private:
    static bool comp(const Interval &a, const Interval &b) {
        if (a.end != b.end)
            return a.end < b.end; // 先按区间终点升序排序
        else
            return a.start > b.start; // 再按区间起点降序排序, 这样做可以使得重叠区间内 区间长度最小的区间 排在前面
    }

public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int j = 0, cnt = 0; // i 在前， j 在后，两个指针
        for (int i = 1; i < n; ++i) {
            if (intervals[i].start >= intervals[j].end){
                j = i; // 更新 j 指针位置等于 i
            }
            else{
                // 因为 intervals[i].start <  intervals[j].end 两个区间重叠了
                cnt++; // 重叠的区间数目+1
            }
        }
        return cnt;
    }

};