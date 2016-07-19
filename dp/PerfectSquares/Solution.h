//
// Created by YuXiao on 7/19/16.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H
#define LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<int> cntSqures(n + 1, INT_MAX);
        cntSqures[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                cntSqures[i] = min(cntSqures[i], cntSqures[i - j * j] + 1);
            }
        }

        return cntSqures.back();
    }
};


#endif //LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H
