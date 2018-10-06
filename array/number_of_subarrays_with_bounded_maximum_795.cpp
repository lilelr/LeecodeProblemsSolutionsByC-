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
//
//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117612/C++-O(n)-solution-with-explanations
//
//The idea is to keep track of 3 things while iterating: the number of valid subarrays (res), the number of valid subarray starting points (heads), and the number of not-yet valid starting points (tails).
//
//Values between L and R are heads. Every contiguous value afterwards that is less than R afterwards can extend them, creating new subarrays.
//Values less than L are tails. If they connect to a head later in the array, they become a head for valid subarrays.
//Values greater than R are combo breakers. They stop all heads and tails from forming from subarrays.
//Therefore, we keep a rolling count of valid subarrays as we iterate through A, the main array.
//
//If a head is encountered, it joins the existing heads to form subarrays at each iteration. All tails are promoted to heads. All existing heads create a new valid subarray.
//The new head creates subarray of a single element ([head])
//Each promoted head creates subarrays from its tail index to current index (e.g. [tail1, tail2, head, ...], encountering head promotes tail1 and tail2 to heads and creates [tail1, tail2, head] and [tail2, head])
//If a tail is encountered, all existing heads can create another subarray with it. The tail remains useless until it encounters a head (see above).
//If a combo breaker is met, all existing heads and tails become useless, and are reset to 0.
//Counts of new subarrays (i.e. head count) are added to res at each iteration, if valid.
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, heads = 0, tails = 0;
        for (int val : A) {
            if (L <= val && val <= R) {
                // val is a head. All tails promoted to heads
                heads+= tails + 1;
                tails = 0;
                res += heads;
            }
            else if (val < L) {
                // val is a tail, can extend existing subarrays
                tails++;
                res += heads;
            }
            else {
                // combo breaker
                heads = 0;
                tails = 0;
            }
        }
        return res;
    }

};

int main() {

}