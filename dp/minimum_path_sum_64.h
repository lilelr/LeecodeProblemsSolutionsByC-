//
// Created by YuXiao on 3/21/18.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC_MINIMUM_PATH_SUM_64_H
#define LEECODEPROBLEMSSOLUTIONSBYC_MINIMUM_PATH_SUM_64_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
// https://leetcode.com/problems/minimum-path-sum/description/
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result_grid[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    result_grid[0][0] = grid[0][0];
                } else if (i == 0) {
                    result_grid[0][j] = result_grid[0][j - 1] + grid[0][j];
                } else if (j == 0) {
                    result_grid[i][0] = result_grid[i - 1][0] + grid[i][0];
                } else {
                    result_grid[i][j] = min(result_grid[i - 1][j], result_grid[i][j - 1]) + grid[i][j];
                }

            }
        }
        return result_grid[m - 1][n - 1];
    }
};


#endif //LEECODEPROBLEMSSOLUTIONSBYC_MINIMUM_PATH_SUM_64_H
