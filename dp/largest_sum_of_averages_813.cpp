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
//https://leetcode.com/problems/largest-sum-of-averages/discuss/122775/Java-bottom-up-DP-with-Explanation
////Let f[i][j]be the largest sum of averages for first i + 1 numbers(A[0], A[1], ... , A[i]) tojgroups. f[i][j] consists of two parts: first j-1 groups' averages and the last group' s average. Considering the last group, its last number must be A[i] and its first number can be from A[0] to A[i]. Suppose the last group starts from A[p+1], we can easily get the average form A[p+1] to A[i]. The sum of first j-1 groups' average is f[p][j-1] which we have got before. So now we can write the DP equation:
//f[i][j] = max {f[p][j-1] + (A[p+1] + A[p+2] + ... + A[i]) / (i - p)}, p = 0,1,...,i-1


class Solution {
public:
    double largestSumOfAverages(vector<int> &A, int K) {
        if (K == 0 || A.size() == 0) {
            return 0;
        }

        int len = A.size();
        double f[len][K + 1];
        double s[len + 1];
        for (int i = 1; i <= len; i++) {
            s[i] = s[i - 1] + A[i - 1];
            f[i - 1][1] = s[i] / i;
        }

        for (int j = 2; j <= K; j++) {
            for (int i = 0; i < len; i++) {
                double ma = 0;

                for (int p = 0; p < i; p++) {
                    double sum = f[p][j - 1] + (s[i + 1] - s[p + 1]) / (i - p);
                    if (p == 0) {
                        ma = sum;
                    } else {
                        ma = max(ma, sum);
                    }
                }

                f[i][j] = ma;
            }
        }
        return f[len - 1][K];
    }
};

int main() {

}