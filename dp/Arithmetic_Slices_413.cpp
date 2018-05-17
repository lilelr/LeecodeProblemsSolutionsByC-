//
// Created by YuXiao on 5/17/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>

using namespace std;
// https://leetcode.com/problems/arithmetic-slices/description/
//https://leetcode.com/problems/arithmetic-slices/discuss/90058/Simple-Java-solution-9-lines-2ms
// Nice solution! use "sum += curr", because curr is equal to the number of new arithmetic that contains the A[i] as the last element.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int cur = 0, sum = 0;
        int len = A.size();
        for (int i = 2; i < len; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                cur += 1;
                sum += cur;
            } else {
                cur = 0;
            }
        }
        return sum;
    }
};