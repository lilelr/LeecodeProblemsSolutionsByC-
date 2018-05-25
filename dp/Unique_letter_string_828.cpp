//
// Created by YuXiao on 5/24/18.
//
// https://leetcode.com/problems/unique-letter-string/description/
// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
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
typedef long long LL;

class Solution {
public:
    int uniqueLetterString(string S) {
        vector<vector<int>> hash(26, vector<int>());
        int n = S.size();
        vector<LL> dp(n + 1, 0);
        const int mod = 1e9 + 7;
        dp[1] = 1;
        hash[S[0] - 'A'].push_back(0);
        for (int i = 1; i < n; i++) {
            int c = S[i] - 'A';
            dp[i + 1] = dp[i] + 1;
            int diff = dp[i] - dp[i - 1]; //previous addition
            if (hash[c].size()) { // same char in the front
                int j = hash[c].back();
                int k;
                if (hash[c].size() > 1) {
                    k = hash[c][0];
                } else {
                    k = -1;
                }
                dp[i + 1] += diff + (i - j - 1) - (j - k); // we add 1 to j+1 and minus 1 to k+1
            } else { // there is no same char in the front
                dp[i + 1] += i + diff; // we add one to all previous solution
            }
            hash[c].push_back(i);
            if (hash[c].size() > 2) {
                hash[c][0] = hash[c][1];
                hash[c][1] = hash[c][2];
                hash[c].pop_back();
            }
        }
        return dp[n] % mod;
    }
};


int main() {
    Solution s;
//    string str = "ABC";
    string str = "ABA";
    int res = s.uniqueLetterString(str);
    cout<<res<<endl;
}