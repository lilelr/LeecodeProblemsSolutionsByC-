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
//https://leetcode.com/problems/total-hamming-distance/description/
///Java O(n) time O(1) Space
//
//compton_scatter
//        compton_scatter
//1900
//For each bit position 1-32 in a 32-bit integer, we count the number of integers in the array which have that bit set. Then, if there are n integers in the array and k of them have a particular bit set and (n-k) do not, then that bit contributes k*(n-k) hamming distance to the total.
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total =0, n = nums.size();
        for(int j=0;j<32;j++){
            int bit_cnt =0;
            for(int i=0;i<n;i++){
                bit_cnt += (nums[i] >> j) & 1;
            }
            int temp = bit_cnt *(n-bit_cnt);
            total += temp;
        }
        return total;
    }
};

int main() {

}