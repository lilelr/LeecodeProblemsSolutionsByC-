//
// Created by YuXiao on 3/26/18.
// https://leetcode.com/problems/gas-station/description/

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start =0;
        int end = gas.size() -1;
        int capacity = 0;
        while (start<=end){
            if(capacity + gas[start] >= cost[start]){
                capacity = capacity + gas[start] - cost[start];
                start++;
            }else {
                capacity = capacity + gas[end] - cost[end];
                end--;
            }
        }

        return capacity >=0 ? start%gas.size() : -1;
    }
};