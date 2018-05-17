//
// Created by YuXiao on 5/15/18.

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
// https://leetcode.com/problems/frog-jump/description/
using namespace std;
// https://leetcode.com/problems/frog-jump/discuss/128675/Share-three-c++-solutions
class Solution {
public:
    // Hashmap set
    bool canCross(vector<int> &stones) {
        int n = stones.size(), ans = 0;
        unordered_map<int, set<int>> m;
        for (auto x: stones) m[x] = {};
        m[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (int last_step: m[stones[i]]) {
                for (int next_step = last_step - 1; next_step <= last_step + 1; next_step++) {
                    if (next_step > 0 && m.count(stones[i] + next_step)) {
                        m[stones[i] + next_step].insert(next_step);
                    }
                }
            }
        }
        bool res = !m[stones[n - 1]].empty();
        return res;
    }


    // hashmap dfs
    bool canCross2(vector<int>& stones) {
        unordered_map<int, bool> m;
        return dfs(0, stones,stones.size(),0,m );
    }

    bool dfs(int ix,vector<int>& stones, int n, int step, unordered_map<int, bool>& m){
        int key = ix | step<< 11; //combine step size and start position into a new hash key.
        if (m.count(key))return m[key];
        for(int i = ix+1; i< n; ++i){
            int jump = stones[i] - stones[ix];
            if(jump>step+1) return m[key] =false;
            if(jump>=step-1  && dfs(i, stones, n, jump,m))
                return m[key]=true;
        }
        return m[key] = ix == n-1;
    }

    // priority queue
    bool canCross3(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1)return false;
        priority_queue<pair<int, int>> q;
        q.push({1,1});
        while(!q.empty()) {
            auto cur = q.top(); q.pop();
            int pos=stones[cur.first], step=cur.second;
            if(cur.first == n - 1)  return true;
            for(int i=cur.first+1;i<n;i++) {
                int jump = stones[i] - pos;
                if(jump >= step-1 && jump <= step+1) {
                    q.push({i,jump});
                } else if(jump >step+ 1){
                    if(jump > pos+10) return false;
                    break;
                }
            }
        }
        return false;
    }


};

int main() {

}