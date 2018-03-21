//
// Created by YuXiao on 3/21/18.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC_SCRAMBLE_STRING_87_H
#define LEECODEPROBLEMSSOLUTIONSBYC_SCRAMBLE_STRING_87_H

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if(s1.compare(s2)==0){
            return true;
        }
        size_t str_size = s1.size();
        int same_alphabets[26] = {0};
        for (int i = 0; i < str_size; i++) {
            int temp = s1[i] - 'a';
            same_alphabets[s1[i] - 'a']++;
            same_alphabets[s2[i] - 'a']--;
        }
        for (auto item:same_alphabets) {
            if (item != 0) {
                return false;
            }
        }

        for (int i = 1; i < str_size; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(str_size - i)) &&
                isScramble(s1.substr(i), s2.substr(0, str_size - i))) {
                return true;
            }

            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
        }

        return false;
    }
};
//"a"
//"a"
//"rgeat"
//"great"
//"rgeat"
//"eatrg"
//"abcd"
//"bdac"

#endif //LEECODEPROBLEMSSOLUTIONSBYC_SCRAMBLE_STRING_87_H
