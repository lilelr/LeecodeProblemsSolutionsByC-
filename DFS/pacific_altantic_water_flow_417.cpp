#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

const int maxn = 0x3f3f3f3f;
// DFS + 回溯
class Solution{
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>>res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 方向
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                bool reachP = false, reachA = false;
                DFS(res, matrix, i, j, m, n, reachP, reachA);
                if(reachP && reachA) res.push_back({i, j});
            }
        return res;
    }

    void DFS(vector<pair<int, int>>& res, vector<vector<int>>& matrix, int r, int c, int m, int n, bool& reachP, bool& reachA){
        if(matrix[r][c] == -1 || reachP && reachA) return;
        int tmp = matrix[r][c];
        matrix[r][c] = -1; // -1表示访问过
        for(int i = 0; i < 4; i++){
            int R = r + dir[i].first, C = c + dir[i].second;
            if(R < 0 || C < 0) reachP = true;
            else if(R == m || C == n) reachA = true;
            else if(matrix[R][C] <= tmp) DFS(res, matrix, R, C, m, n, reachP, reachA);
        }
        matrix[r][c] = tmp; // 与matrix[r][c] = -1 对应，回溯
    }

private:
    vector<pair<int, int>>dir;
};


int main() {

    return 0;
}