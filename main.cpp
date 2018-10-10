#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <list>
#include <unordered_set>

//https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100733/Java-Binary-Search-with-Detailed-Explanation
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        vector<unordered_map<int,int>> dp(n,unordered_map<int,int>());
        // dp[i][diff] 以当前A[i] 为数组末尾元素，差为diff 的数组个数
        unordered_set<int> mmset(A.begin(), A.end());
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];

                int add_on = 0;
                if(dp[j].count(diff) !=0){
                    add_on = dp[j][diff];
                }

                if(mmset.count(A[i]+diff)!=0){
                    add_on+=1;
                }
                dp[i][diff]+=add_on;
                res+=add_on;
            }
        }
    }

};

int main() {

}