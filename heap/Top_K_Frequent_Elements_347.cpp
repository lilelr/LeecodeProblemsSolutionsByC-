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

// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    // priority_queue
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mymap;
        for (int num:nums) {
            mymap[num]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency, second is number
        priority_queue<pair<int, int>> pq;
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int) mymap.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }

    // make_heap
    vector<int> topKFrequent2(vector<int> &nums, int k) {
        unordered_map<int, int> fq;
        auto cmp = [&](int a, int b) {
            return fq[a] > fq[b];
        };
        //priority_queue<int,vector<int>,function<bool(int,int)> >pq(cmp);
        for (auto ele:nums)
            fq[ele] += 1;

        vector<int> res;
        auto it = fq.begin();
        for (int i = 0; i < k; i++)
            res.push_back(it++->first);
        make_heap(res.begin(), res.end(), cmp);
        while (it != fq.end()) {
            if (fq[it->first] > fq[res.front()]) {
                pop_heap(res.begin(), res.end(), cmp);
                res.back() = it->first;
                push_heap(res.begin(), res.end(), cmp);
            }
            it++;
        }

        return res;
    }
};


int main() {

}
