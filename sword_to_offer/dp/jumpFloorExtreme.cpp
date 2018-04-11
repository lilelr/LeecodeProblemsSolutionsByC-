//
// Created by YuXiao on 4/11/18.
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
    int jumpFloorII(int number) {
        if(number <=0) return 0;
        if(number ==1) return 1;
        if(number ==2) return 2;
        vector<int> status(number+1,0);
        status[0] =0;
        status[1]= 1;
        status[2] = 2;
        for(int i=3;i<=number;i++){
            for(int j=1;j<i;j++){
                status[i] += status[j];
            }
            status[i] +=1;
        }
        return status[number];
    }
};

