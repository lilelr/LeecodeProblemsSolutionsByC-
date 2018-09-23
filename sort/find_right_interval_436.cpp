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

//https://leetcode.com/problems/find-right-interval/description/
class Solution {
//  Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> hash; // 红黑树本来就是棵已按照键值排好序的二叉排序树
        vector<int> res;
        int n= intervals.size();
        for(int i=0;i<n;i++){
            hash[intervals[i].start] = i;
        }
        for(auto in:intervals){
            auto iter = hash.lower_bound(in.end);
            if(iter == hash.end()){
                res.push_back(-1);
            }else{
                res.push_back(iter->second);
            }
        }

        return res;
    }

};