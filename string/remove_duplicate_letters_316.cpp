//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
// https://leetcode.com/problems/remove-duplicate-letters/discuss/76766/Easy-to-understand-iterative-Java-solution

// The basic idea is to find out the smallest result letter by letter (one letter at a time). Here is the thinking process for input "cbacdcbc":

//find out the last appeared position for each letter;
//c - 7
//b - 6
//a - 2
//d - 4
//find out the smallest index from the map in step 1 (a - 2);
//the first letter in the final result must be the smallest letter from index 0 to index 2;
//repeat step 2 to 3 to find out remaining letters.
//the smallest letter from index 0 to index 2: a
//        the smallest letter from index 3 to index 4: c
//        the smallest letter from index 4 to index 4: d
//        the smallest letter from index 5 to index 6: b
//        so the result is "acdb"
//
//Notes:
//
//        after one letter is determined in step 3, it need to be removed from the "last appeared position map", and the same letter should be ignored in the following steps
//in step 3, the beginning index of the search range should be the index of previous determined letter plus one

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.length();
        if (len <= 1) return s;

        map<char, int> last_pos_map;
        for (int i = 0; i < len; i++) {
            if(last_pos_map.find(s[i])==last_pos_map.end()){
                last_pos_map.insert({s[i], i});
            }else{
                last_pos_map[s[i]] = i;
            }
        }

        int len2 = last_pos_map.size();
        char result[last_pos_map.size()+1];
        int begin = 0, end = find_min_last_pos(last_pos_map);

        for (int i = 0; i < len2; i++) {
            char min_char = 'z' + 1;
            for (int k = begin; k <= end; k++) {
                char tmp = s[k];
                if (last_pos_map.find(tmp) != last_pos_map.end() && tmp < min_char) {
                    min_char = tmp;
                    begin = k + 1;
                }
            }
            result[i] = min_char;
            if (i == len2 - 1) break;
            last_pos_map.erase(min_char);

            if (s[end] == min_char) end = find_min_last_pos(last_pos_map);
        }
        result[len2]='\0';
        string res = result;
        return res;
    }

private:
    int find_min_last_pos(map<char, int> &last_pos_map) {
        if (last_pos_map.empty()) return -1;
        int min_last_pos = INT_MAX;
        auto it = last_pos_map.begin();
        for (; it != last_pos_map.end(); it++) {
            min_last_pos = min(min_last_pos, it->second);
        }
        return min_last_pos;
    }
};


int main() {
    Solution s;
    string str = "cbacdcbc";
    string str1 = "bcabc";
    string res = s.removeDuplicateLetters(str);
    cout<<res<<endl;
}