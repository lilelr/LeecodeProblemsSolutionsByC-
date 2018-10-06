#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;
// https://leetcode.com/problems/k-similar-strings/discuss/139926/C++-BFS-solution

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B) return 0;

        unordered_set<string> visited;
        queue<pair<string, int>> que; // pair: key-> string, value -> 下标
        int n = A.size();
        int step = 0;
        int i = 0;

        for (; i < n; i++) {
            if (A[i] != B[i]) break;
        }

        que.push({A, i});
        visited.insert(A);

        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; i++) {
                string cur = move(que.front().first);
                int index = que.front().second;
                que.pop();

                if (cur == B) return step;

                while (cur[index] == B[index]) {
                    index++;
                }

                for (int j = index + 1; j < n; j++) {
                    if (cur[j] == B[index] && cur[j] != B[j]) {
                        swap(cur[j], cur[index]); // 交换

                        if (visited.count(cur) == 0) {
                            que.push({cur, index + 1});
                        }

                        swap(cur[j], cur[index]); // 回溯,还原，与50行对应，保证只交换一次
                    }
                }
            }

            step++;
        }

        return step;
    }

};

int main() {

}