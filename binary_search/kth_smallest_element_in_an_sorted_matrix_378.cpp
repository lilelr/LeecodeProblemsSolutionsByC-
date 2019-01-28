#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85182/My-solution-using-Binary-Search-in-C++
using namespace std;

class Solution {
public:
//    The idea is to do a binary search in the range from matrix[0][0] to matrix[n-1][n-1]. At each iteration, count numbers smaller than 'mid' in each row using binary search. If total count is too small, then search a larger mid, otherwise search a smaller mid.
//
//    The idea is not hard to understand, but the details should be clarified for you to have better understanding about binary search.
//    (i) why use upper_bound here, not lower_bound?
//    Ans: upper_bound find the first position where x > key, while lower_bound find the first position where x >= key. Here I want to get the count that how many entries in each row are smaller or equal to 'mid', if we use lower_bound, we will lose the part that are equal to 'mid'.
//    (ii) why search left with condition count < k, not count <= k ?
//    Ans: This is a common issue when it comes to binary search. Just keep in mind: when we quit the binary search, 'low' will point to the smallest position where the if-clause is not qualified (count >= k for this example here), and 'high' will point to the last position where if-clause is qualified (count < k for this example here). In this case, we want to find the smallest possible value which has count >= k, so we use (count < k) as the if-clause.


    int kthSmallest(vector<vector<int>> &matrix, int k) {
        const int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};