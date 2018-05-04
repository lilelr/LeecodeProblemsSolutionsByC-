//
// Created by YuXiao on 5/4/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
// 圆圈中最后剩下的数
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n <1 || m <1){
            return -1;
        }
        int last = 0;
        for(int i=2;i<=n;i++){
            last = (last + m)%i;  // f(n,m) = ( f(n-1,m) + m ) % n
        }
        return last;
    }
};