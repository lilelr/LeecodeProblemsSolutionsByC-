#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/130427/()-92
using namespace std;

// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87749/Two-short-C%2B%2B-solutions-(3ms-and-6ms)
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longest_substring_recursive(s, k, 0, s.size());
    }

    int longest_substring_recursive(const string &s, int k, int first, int last) {
        int count[26] = {0};
        for (int i = first; i < last; i++) {
            ++count[s[i] - 'a'];
        }

        int max_len = 0;
        for (int i = first; i < last;) {
            while (i < last && count[s[i] - 'a'] < k) ++i;
            if (i == last) break;
            int l = i;
            while (l < last && count[s[l] - 'a'] >= k) ++l;
            // all chars appear more than k times
            if (i == first && l == last)
                return last -
                       first; // make sure this condition satisfied, it means all the chars in this segment appear more than k times.  Otherwise , recursive
            max_len = max(max_len, longest_substring_recursive(s, k, i, l));
            i = l; // continue other segment
        }

        return max_len;
    }


    int longestSubstring2(string s, int k) {
        int max_len = 0;
        for (int first = 0; first + k <= s.size();) {
            int count[26] = {0};
            int mask = 0;
            int max_last = first;
            for (int last = first; last < s.size(); ++last) {
                int i = s[last] - 'a';
                count[i]++;
                if (count[i] < k) mask |= (1 << i);
                else mask &= (~(1 << i));

                if (mask == 0) {
                    max_len = max(max_len, last - first + 1);
                    max_last = last;
                }
            }
            first = max_last + 1;
        }
        return max_len;
    }
};