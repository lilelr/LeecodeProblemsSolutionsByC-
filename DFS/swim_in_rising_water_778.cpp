
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/swim-in-rising-water/discuss/113758/C++-two-solutions-Binary-Search+DFS-and-Dijkstra+BFS-O(n2logn)-11ms
class Solution {
public:

    int swimInWater_Dijistra_priority_Queue(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i+1];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }

        return -1;
    }

    int swim_in_water_Dijkstra_with_BFS(vector<vector<int>> &grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n - 1][n - 1]);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // 最小堆

        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (pq.empty()) {
            auto cur = pq.top();
            ans = max(ans, cur[0]);
            queue<pair<int, int>> myq;
            myq.push({cur[1], cur[2]});
            while (!myq.empty()) {
                auto &p = myq.front();
                myq.pop();
                if (p.first == n - 1 && p.second == n - 1) return ans;
                for (int i = 0; i < 4; i++) {
                    int r = p.first + dir[i], c = p.second + dir[i + 1];
                    if (r >= 0 && r < 0 && c >= 0 && c < n && visited[r][c] == 0) {
                        visited[r][c] = 1;
                        if (grid[r][c] <= ans) {
                            myq.push({r, c});
                        } else {
                            pq.push({grid[r][c], r, c});
                        }
                    }
                }
            }
            return -1;
        }
    }


    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int low = grid[0][0], hi = n * n - 1;
        while (low < hi) {
            int mid = low + (hi - low) / 2;
            if (valid(grid, mid))
                hi = mid;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    bool valid(vector<vector<int>> &grid, int waterHeight) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> dir({-1, 0, 1, 0, -1}); // 上右下左
        return dfs(grid, visited, dir, waterHeight, 0, 0, n);
    }

    bool
    dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<int> &dir, int waterHeight, int row, int col,
        int n) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int r = row + dir[i], c = col + dir[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0 && grid[r][c] <= waterHeight) {
                if (r == n - 1 && c == n - 1) return true;
                if (dfs(grid, visited, dir, waterHeight, r, c, n)) return true;
            }
        }
        return false;
    }
};

int main() {
      vector<vector<int>> grid(2,vector<int>(2));
    grid[0] = {0,2};
    grid[1] = {1,3};
    Solution s;
    int res = s.swimInWater_Dijistra_priority_Queue(grid);
    cout<<res<<endl;


}