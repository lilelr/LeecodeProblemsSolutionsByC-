// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include<cstdlib> //abs

using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());//sort time
        int res = 24 * 60; //max is 24h 
        for(int i = 0; i < n; i++) {
            int timeDiff = diff(timePoints[i], timePoints[(i+1)%n]);
            timeDiff = min(timeDiff, 1440-timeDiff);//compare with 1440-timeDiff
            res = min(timeDiff, res);
        }
        return res;
    }

private:
    int diff(string t1, string t2) {//calculate time difference between neighbours
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 5));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 5));
        return abs((h1-h2)*60 + m1 -m2);
    }


};