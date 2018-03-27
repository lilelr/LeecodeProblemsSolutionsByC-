//
// Created by YuXiao on 3/27/18.
//https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:

    void reverse_word(string& s, int i,int j){
        while (i<j){
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
    void reverseWords(string& s) {
        int i=0,j=0;
        int l = 0;
        int len = s.length();
        int word_count = 0;
        while (true){
            while (i<len && s[i] ==' ') i++;
            if(i==len) break;
            if(word_count) {
                s[j++] = ' ';
            }
            l = j;
            while (i<len && s[i] !=' '){
                s[j] = s[i];
                j++;
                i++;
            }
            reverse_word(s,l,j-1);
            word_count++;
        }
        s.resize(j);
        reverse_word(s,0,j-1);
    }
};