//
// Created by YuXiao on 6/6/18.
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
#include <list>

using namespace std;
// https://leetcode.com/problems/contiguous-array/description/
// https://leetcode.com/problems/contiguous-array/discuss/99648/O(n)-fast-C++-solution
int findMaxLength(vector<int> &nums) {
    map<int, int> myMap;
    map<int, int>::iterator it;
    int sum = 0;
    int max_len = 0;
    myMap[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 0) ? -1 : 1;
        it = myMap.find(sum);
        if (it != myMap.end()) {
            max_len = max(max_len, i - it->second);
        } else {
            myMap[sum] = i;
        }
    }
    return max_len;

}
