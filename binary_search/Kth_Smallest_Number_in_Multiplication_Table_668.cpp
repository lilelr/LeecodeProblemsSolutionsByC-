//
// Created by YuXiao on 6/8/18.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
// 注意table 的数的排列特点
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/solution/
class Solution {
public:
    bool enough(int x, int m, int n, int k) {
//        int count = 0;
//        for (int i = 1; i <= m; i++) {
//            count += min(x / i, n);
//        }
//        return count >= k;

        int cnt =0;
        for(int i=1;i<=m;i++){
            cnt += min(x/i,n);
        }
        return cnt>=k;
    }

int findKthNumber(int m, int n, int k) {
//        int lo = 1, hi = m * n;
//        while (lo < hi) {
//            int mi = lo + (hi - lo) / 2;
//            if (!enough(mi, m, n, k)) lo = mi + 1;
//            else hi = mi;
//        }

    int lo =1 , hi = m*n;
    while (lo<hi){
        int mi =lo + (hi - lo)/2;
        if(!enough(mi,m,n,k)){
            lo = mi+1;
        }else {
            hi = mi;
        }
    }
        return lo;
    }
};

