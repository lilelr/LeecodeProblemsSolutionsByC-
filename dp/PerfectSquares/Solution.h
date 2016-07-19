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

    // 12ms static vector static is not used, it would cost 312ms.
    int numSquares2(int n) {
        if (n <= 0) {
            return 0;
        }

        static vector<int> cntSqures({0});
        while (cntSqures.size() <= n) {
            int curSize = cntSqures.size();
            int newSqures = INT_MAX;
            for (int j = 1; j * j <= curSize; j++) {
                newSqures = min(newSqures, cntSqures[curSize - j * j] + 1);
            }
            cntSqures.push_back(newSqures);
        }
        return cntSqures[n];
    }
};


#endif //LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H
