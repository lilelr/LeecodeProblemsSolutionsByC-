
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
//https://leetcode.com/problems/maximum-product-subarray/description/
using namespace std;
// https://leetcode.com/problems/freedom-trail/description/
// https://leetcode.com/problems/freedom-trail/discuss/98897/Java-Clear-Solution-dfs+memoization
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // store the result that is the max we have found so far
        int ans = nums[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for(int i=1,imax=ans,imin=ans;i<nums.size();i++){
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if(A[i]<0){
                swap(imax,imin);
            }

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(A[i],imax*A[i]);  // dp
            imin = min(A[i],imin*A[i]);

            // the newly computed max value is a candidate for our global result
            ans = max(r,imax);
        }
        return ans;
    }
};