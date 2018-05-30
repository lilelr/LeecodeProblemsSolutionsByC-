
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef int SID;
typedef int RID;

//https://leetcode.com/problems/bus-routes/discuss/129522/C++-(200ms)-BFS-solution
class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
        if (S == T) {
            return 0;
        }

        const int n = routes.size();

        // build  bus-stop to bus-route mapping(one -> many)
        unordered_map<SID, unordered_set<RID>> s2r;
        for (RID rid = 0; rid < n; rid++) {
            for (SID sid: routes[rid]) {
                s2r[sid].insert(rid);
            }
        }

        // build route graph
        unordered_map<RID, unordered_set<RID>> graph;
        for (RID rid = 0; rid < n; rid++) {
            for (SID sid: routes[rid]) {
                for (RID nextRid : s2r[sid]) {
                    if (rid != nextRid) {
                        graph[rid].insert(nextRid);
                    }
                }
            }
        }

        // target routes we're looking for (one "T" belongs to many routes)
        const unordered_set<RID> targets(s2r[T].begin(), s2r[T].end());
        unordered_set<RID> visited;

        // start routes inqueue
        queue<RID> q;
        for (auto rid:s2r[S]) {
            q.push(rid);
        }
        int result = 0;

        // BFS route
        while (!q.empty()) {
            result++;
            const int n = q.size();
            for (int i = 0; i < n; i++) { // 层次遍历，n 等于这一层的所有route 数
                const RID rid = q.front();
                q.pop();
                if (targets.find(rid) != targets.end()) {
                    return result;
                }
                visited.insert(rid);

                // next route id inqueue
                for (RID nextRid: graph[rid]) {
                    if (visited.find(nextRid) != visited.end()) {
                        continue;
                    }
                    q.push(nextRid);
                }
            }
        }
        return -1;

    }
};


int main() {

}