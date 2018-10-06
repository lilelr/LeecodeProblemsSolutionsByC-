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
//https://leetcode.com/problems/longest-palindromic-substring/description/
// https://leetcode.com/problems/longest-palindromic-substring/discuss/3298/My-Solution-Is-Naive-It-Cost-O(n2)-Is-there-Any-Solution-faster
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int maxLength = 1;
        string res;

        if(s.length()==1)
            return s;
        int low, high;
        for (int i = 1; i < s.length(); ++i)
        {
            low = i - 1;
            high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high <s.length() && s[low] == s[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }
        res = s.substr(start,maxLength);
        return res;


    }
};

int main() {

}