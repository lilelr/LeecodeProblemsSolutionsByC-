//
// Created by YuXiao on 3/25/
//https://leetcode.com/problems/jump-game-ii/description/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    int jump(vector<int> &nums) {
        int len = nums.size();
        if (len <= 1) return 0;

        int i, j;
        int reachable = nums[0];
        int pre_reachable;
        int next_range=reachable;
        i = 0;
        int count = 1;
        while (i < len) {
            if (reachable >= (len - 1)) return count;
            pre_reachable = reachable;
            for (j = i + 1; j <= pre_reachable; j++) {
                reachable = max(reachable, j + nums[j]);
            }
            if (reachable != pre_reachable) {
                count++;
            }
            i = pre_reachable;
        }
        return count;
    }
};


int main() {
        Solution solution;
        vector<int> test_vec{1,2,3};
        vector<int> test1_vec{2,3,1,4};
    vector<int> test2_vec{1,1,1,1};

//    int res = solution.jump(test1_vec);
//        cout<<res<<endl;

    int res2 = solution.jump(test2_vec);
    cout<<res2<<endl;
}