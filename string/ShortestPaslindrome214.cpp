//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
// https://leetcode.com/problems/shortest-palindrome/description/
// https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation
// KMP 求最短回文字符串
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string copy_s = s;
        reverse(copy_s.begin(), copy_s.end());
        string temp_str = s + '#' + copy_s;
        vector<int> table = get_KMP_table(temp_str);
        int table_len = temp_str.length();
        string remain = s.substr(table[table_len -1]+1);
        cout<<"remain "<<remain<<endl;
        reverse(remain.begin(), remain.end());
        string res = remain + s;
        return res;
    }
//// KMP table:
//
//    c a t a c b # b c a t a c
//
//    0 0 0 0 1 0 0 0 1 2 3 4 5
private:
    vector<int> get_KMP_table(string temp_str) {
        vector<int> table(temp_str.length());
        int j = 0, k = -1;
        table[0] = -1;
        while (j < temp_str.length() - 1) {
            if (k == -1 || temp_str[k] == temp_str[j]) {
                table[++j] = ++k;
            } else {
                k = table[k];
            }
        }
//        for(auto& letter:temp_str){
//            cout<<letter<<" ";
//        }
//        cout<<endl;
//        for (auto& item:table){
//            cout<<item << " ";
//        }
//        cout<<endl;
        return table;

    }
};


int main() {
    Solution so;
//    string str = "catacb";
    string str1 = "aacecaaa";
    string res = so.shortestPalindrome(str1);
    cout<<res<<endl;
}