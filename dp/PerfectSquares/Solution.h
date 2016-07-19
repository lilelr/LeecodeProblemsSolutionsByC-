//
// Created by YuXiao on 7/19/16.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H
#define LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
//https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics/2
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

    //BFS 80ms
    int numSquares3(int n) {
        if(n <=0){
            return 0;
        }

        vector<int> perfectSquares;
        vector<int> cntPerfectSquares(n);

        for(int i=1;i*i<=n;i++){
            perfectSquares.push_back(i*i);
            cntPerfectSquares[i*i-1] = 1;
        }

        if(perfectSquares.back() == n){
            return 1;
        }

        queue<int> searchQ;
        for(auto& item: perfectSquares){
            searchQ.push(item);
        }

        int currCntPerfectSquares = 1;
        while (!searchQ.empty()){
            currCntPerfectSquares++;

            int searchQSize = searchQ.size();
            for(int i=0;i< searchQSize;i++){
                int frontItem = searchQ.front();
                for(auto& j:perfectSquares){
                    if(frontItem+j == n){
                        return currCntPerfectSquares;
                    }
                    else if ((frontItem+j <n) && (cntPerfectSquares[frontItem+j-1] == 0)){
                        cntPerfectSquares[frontItem+j-1] = currCntPerfectSquares;
                        searchQ.push(frontItem+j);
                    }
                    else if(frontItem+j > n){
                        break;
                    }
                }
                searchQ.pop();
            }
        }
        return 0;
    }

};


#endif //LEECODEPROBLEMSSOLUTIONSBYC__SOLUTION_H
