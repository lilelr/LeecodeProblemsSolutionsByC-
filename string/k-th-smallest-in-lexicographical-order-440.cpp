//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/92242/ConciseEasy-to-understand-Java-5ms-solution-with-Explaination
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while (k > 0) {
            int steps = cal_steps(n, curr, curr + 1);
            cout<<"K:"<<k<<" "<<"curr:"<<curr<<" steps:"<<steps<<endl;
            if (steps <= k) {
                curr += 1; // n1 = n2
                k -= steps;
            } else { // steps > k,
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    int cal_steps(int n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += std::min((long)n + 1, n2) - n1;
            cout<<"n1: "<<n1<<" n2: "<<n2<<" steps:"<<steps<<endl;

            n1 *= 10;
            n2 *= 10;

        }
        return steps;
    }
};


int main() {
    Solution s;
    int res = s.findKthNumber(13,3);
    cout<<res<<endl;

}