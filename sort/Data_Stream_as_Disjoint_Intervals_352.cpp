
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        if(val ==2){
            int tmp=2;
            cout<<tmp<<endl;
        }
        auto newInterval = Interval(val, val);
        // [2,2] lowerbound 为[., 1] upperbound为[3,.]
        auto cmp = [](Interval a, Interval b) { return a.end + 1 < b.start; };
        // lower_bound 和 upper_bound 的经典使用
        auto it0 = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);
        auto it1 = upper_bound(intervals.begin(), intervals.end(), newInterval, cmp);

        if (it0 < it1) {
            newInterval.start = min(newInterval.start, (*it0).start);
            newInterval.end = max(newInterval.end, (*(it1 - 1)).end);
            intervals.erase(it0, it1);
        }

        intervals.insert(it0, newInterval);

    }

    vector<Interval> getIntervals() {
        return intervals;
    }


private:
    vector<Interval> intervals;


};

int main(){
    SummaryRanges s;
    s.addNum(1);
    s.addNum(3);
    s.addNum(1);
    return 0;
}
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */