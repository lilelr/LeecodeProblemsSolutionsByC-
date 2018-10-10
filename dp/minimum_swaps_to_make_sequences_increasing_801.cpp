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
    // https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
    //swap[n] means the minimum swaps to make the A[i] and B[i] sequences increasing for 0 <= i <= n in condition that we swap A[n] and B[n]
//    not_swap[n] is the same with A[n] and B[n] not swapped.
    int minSwap(vector<int> &A, vector<int> &B) {
        int n = A.size();
        int not_swap[1000] = {0};

        int swap[1000] = {1};
        for (int i = 1; i < n; i++) {
            not_swap[i] = swap[i] = n;

            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                not_swap[i] = not_swap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }

            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                not_swap[i] = min(not_swap[i], swap[i - 1]);
                swap[i] = min(swap[i], not_swap[i - 1] + 1);
            }
        }

        return min(swap[n - 1], not_swap[n - 1]);

    }

};

int main() {

}