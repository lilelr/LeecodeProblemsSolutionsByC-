//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:

    bool isIsomorphic(string s, string t)
    {
        vector<char> mapStoT(127, 0);
        vector<char> mapTtoS(127, 0);
        int len = s.length();

        for (int i = 0; i < len; ++i)
        {
            char s_char = s[i], t_char = t[i];
            if (mapStoT[s_char] == 0 && mapTtoS[t_char] == 0)
            {
                mapStoT[s_char] = t_char;
                mapTtoS[t_char] = s_char;
            }
            else if (mapTtoS[t_char] != s_char || mapStoT[s_char] != t_char)
            {
                return false;
            }
        }

        return true;
    }
};


int main() {

}