//
// Created by YuXiao on 4/9/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        if (n == 0) return 0;
        int cnt = 0;
        while (n) {
            n = (n & (n - 1));
            cnt++;
        }
        return cnt;
    }
};


int main() {
    Solution s;
    int res = s.NumberOf1(-1);
    cout<<res<<endl;
}