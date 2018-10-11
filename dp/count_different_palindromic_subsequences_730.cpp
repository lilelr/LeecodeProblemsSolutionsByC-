#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        const int C = 4;   // only has a, b, c, d, 4 chars
        const int kMod = 1E9 + 7;
        // dp[len][c][i] means:
        // start with S[i], with length len substring, how many palindrome starts with char c.
        // see: https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109514/C++-O(N2)-time-O(N)-memory-with-explanation
        vector<vector<int>> pre2(C, vector<int>(n, 0));
        vector<vector<int>> pre1(C, vector<int>(n, 0));
        vector<vector<int>> curr(C, vector<int>(n, 0));
        // len = 0; num = 0;
        // len = 1; num = 1 only when starting char is c.
        for (int i = 0; i < n; i++)
            curr[ctoi(S[i])][i] = 1;
        //
        for (int len = 2; len <= n; len++) {
            pre2 = pre1; // pre2 记录前两轮结果 dp[char c] [index i]
            pre1 = curr; // pre1 记录前一轮结果, curr 记录当前轮结果
            for (int i = 0; i <= n - len; i++) { // 逐个substring 遍历，substring 长度逐渐增大
                int sum = 2;    // aa and a, there are two at least.
                for (int c = 0; c < C; c++) {
                    sum += pre2[c][i + 1]; // 先保存pre2 长度比当前长度小2（即去掉当前substring 首尾元素）的substring 结果
                    sum %= kMod;
                }
                for (int c = 0; c < C; c++) { // 遍历所有字母
                    if (ctoi(S[i]) != c) {
                        curr[c][i] = pre1[c][i + 1]; //palindrome starting char is c
                    } else if (ctoi(S[i + len - 1]) != c) {// 因为 pre1 的substring 长度比当前len少1
                        curr[c][i] = pre1[c][i];
                    } else { // ctoi(S[i]) == c && ctoi(S[i + len - 1]) == c
                        curr[c][i] = sum;
                    }
                }
            }
        }
        //
        int result = 0;
        for (int c = 0; c < C; c++) {
            result += curr[c][0];
            result %= kMod;
        }
        return result;
    }

private:
    int inline ctoi(char &c) {
        return c - 'a';
    }
};

int main() {

}