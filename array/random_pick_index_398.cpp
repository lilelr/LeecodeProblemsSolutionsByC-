
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

//https://en.wikipedia.org/wiki/Reservoir_sampling
// https://leetcode.com/problems/random-pick-index/description/
class Solution {

private:
    vector<int> m_nums;
public:
    Solution(vector<int> nums) {
        m_nums = nums;
    }

    int pick(int target) {
        int n = m_nums.size();
        int res = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (m_nums[i] != target) {
                continue;
            }
            cnt++;
            if (rand() % cnt == 0) {
                res = i;
            }
        }
        return res;
    }

};


int main() {

}