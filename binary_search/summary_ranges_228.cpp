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
// https://leetcode.com/problems/summary-ranges/description/
// https://leetcode.com/problems/summary-ranges/discuss/63280/Not-Brutal-Force:-Best-O(logN)-Binary-Search-Approach
class Solution {
public:
    /**
 * For each starting number S,
     * find its most right element E which satisfies E - S == indexE - indexS.
 * @author xuechao
 *
     *
     *
Input:Input:  [0,2,3,4,6,8,9]
  [0,2,3,4 Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */
    vector<string> summaryRanges(vector<int>& nums) {
            vector<string> res;
        int n = nums.size();
        /// edge cases
        if(n == 0){
            return res;
        }

        int index = 0;
        while (index < n){
            int start  = nums[index];

            // binary search, finding most right element satisfying

            int low = index;
            int high = n-1;
            while (low < high){
                int mid = low + (high - low)/2;
                if(nums[mid] - start > mid -index){
                    // get rid of unsatisfying ones
                    high = mid - 1;
                }else{
                    // keep possible candidate
                    low = mid;
                    if(low == high -1){
                        if(nums[high] == nums[low]+1) {
                            low++;
                        }
                        break;
                    }
                }
            }

//
//
//            Input:Input:  [0,2,3,4,6,8,9]
//            [0,2,3,4 Output: ["0","2->4","6","8->9"]
//            Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
            // index = 3, low = 3, 指向的元素为4
            if(low == index){
                res.push_back(""+start);
            }else{
                res.push_back(start+"->"+nums[low]);
            }
            index = low +1;
        }

        return res;

    }
};

int main() {

}