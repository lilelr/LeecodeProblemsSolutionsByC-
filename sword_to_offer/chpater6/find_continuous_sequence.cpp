
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

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum < 3) {
            return res;
        }
        int small = 1;
        int big = 2;
        int mid = (1 + sum) / 2;
        int cur_sum = small + big;

        while (small < mid) {
            if (cur_sum == sum) {
                vector<int> tmp_ans;
                for (int i = small; i <= big; i++) {
                    tmp_ans.push_back(i);
                }
                res.push_back(tmp_ans);
            }

            while (cur_sum > sum && small < mid) {
                cur_sum -= small;
                small++;
                if (cur_sum == sum) {
                    vector<int> tmp_ans;
                    for (int i = small; i <= big; i++) {
                        tmp_ans.push_back(i);
                    }
                    res.push_back(tmp_ans);
                }
            }
            big++;
            cur_sum += big;
        }
        return res;

    }
};


int main() {
        Solution s;
      auto res = s.FindContinuousSequence(9);
      for(auto item:res){
          for(int i=0;i<item.size();i++){
              cout<<item[i]<<" ";
          }
          cout<<endl;

      }
}