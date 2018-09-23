//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
// https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
//The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is
//
//length of the entire string - number of times of the maximum occurring character in the string
//
//        Given this, we can apply the at most k changes constraint and maintain a sliding window such that
//
//(length of substring - number of times of the maximum occurring character in the substring) <= k
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnts(26, 0);
        int start = 0;
        int max_char_cnt = 0;// 记录滑动窗口中 字母出现最多的次数
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            cnts[s[i] - 'A']++;
            max_char_cnt = max(max_char_cnt, cnts[s[i] - 'A']);
            // sliding window [start,i]
            // (length of substring - number of times of the maximum occurring character in the substring) <= k

            // 大于 k, 则进行滑动窗口大小的缩减，<=k 说明此时可以直接把 非出现次数最多的其余字母全部替换成出现次数最多的字母
            while (i - start + 1 - max_char_cnt > k) {
                cnts[s[start] - 'A']--; // 窗口起始下标start增加
                start++;
                for (int x = 0; x < 26; x++) {
                    max_char_cnt = max(max_char_cnt, cnts[s[x] - 'A']);
                }
            }
            res = max(res, i - start + 1);
        }
        return res;
    }

};


int main() {

}