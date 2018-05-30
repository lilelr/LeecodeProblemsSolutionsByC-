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
//https://leetcode.com/problems/making-a-large-island/discuss/127032/C++JavaPython-Straight-Forward-O(N2)-with-Explanations
// 先dfs 算出 未把 0 变成 1 的 矩形的各个岛屿面积值并用一个index 连接放在一个hashmap 中， 在把其中一个0变成1 ，如果它能够连接两个 index 的岛屿面积值，则加上。
class Solution {
public:
    int N;

    int largestIsland(vector<vector<int>> &grid) {
        N = grid.size();
        int index = 2, res = 0;
        unordered_map<int, int> area;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (grid[x][y] == 1) { // dfs 之后， grid[x][y] 都变成与岛屿面积对应的index 值>=2, 所以下一次遍历到同一个岛屿的point 时 grid[x][y]>=2 不会进入if 语句
                    area[index] = dfs(grid, x, y, index);
                    res = max(res, area[index++]);
                }
            }

        }

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (grid[x][y] == 0) {
                    unordered_set<int> seen = {};
                    int cur = 1;
                    for (auto p: move(x, y)) {
                        index = grid[p.first][p.second];
                        if (index > 1 && seen.count(index) == 0) {
                            seen.insert(index);
                            cur += area[index];
                        }
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;

    }

    vector<pair<int, int>> move(int x, int y) {
        vector<pair<int, int> > res;
        for (auto p: vector<vector<int>> {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}}) {
            if (valid(x + p[0], y + p[1])) {
                res.push_back(make_pair(x + p[0], y + p[1]));
            }
        }
        return res;
    };

    int valid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    int dfs(vector<vector<int>> &grid, int x, int y, int index) {
        int area = 0;
        grid[x][y] = index;
        for (auto p: move(x, y)) {
            if (grid[p.first][p.second] == 1) {
                area += dfs(grid, p.first, p.second, index);
            }
        }
        return area + 1;
    }
};


int main() {

}