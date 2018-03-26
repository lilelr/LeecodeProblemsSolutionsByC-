//
// Created by YuXiao on 3/26/18.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/
class Solution {
public:
  //Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size(), i,cur;
        vector<Interval> res(intervals);
        if(len>1){
            sort(res.begin(),res.end(),[](Interval i, Interval j){return i.start<j.start;});
            for(cur = 0, i=1;i<len;i++){
                if(res[cur].end <res[i].start) {
                    res[++cur] = res[i];
                }
                else{
                    res[cur].end = max(res[i].end,res[cur].end);
                }
            }
            res.resize(cur+1);
        }
        return res;
    }


//    static bool comp(const Interval& a, const Interval& b){
//        return a.start < b.start;
//    }
//    vector<Interval> merge(vector<Interval> &intervals) {
//        vector<Interval> result;
//        if(intervals.empty()){
//            return result;
//        }
//        sort(intervals.begin(), intervals.end(), comp);
//        result.push_back(intervals[0]);
//        for(int i = 1; i < intervals.size(); i++){
//            if(intervals[i].start <= result.back().end){
//                Interval temp(result.back().start, max(result.back().end, intervals[i].end));
//                result.pop_back();
//                result.push_back(temp);
//            }
//            else{
//                result.push_back(intervals[i]);
//            }
//        }
//        return result;
//    }
};