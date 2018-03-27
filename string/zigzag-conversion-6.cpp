//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {

        if (nRows <= 1)
            return s;

        const int len = (int)s.length();
        string *str = new string[nRows];

        int row = 0, step = 1;
        for (int i = 0; i < len; ++i)
        {
            str[row].push_back(s[i]);

            if (row == 0)
                step = 1;
            else if (row == nRows - 1)
                step = -1;

            row += step;
        }

        s.clear();
        for (int j = 0; j < nRows; ++j)
        {
            s.append(str[j]);
        }

        delete[] str;
        return s;
    }

    string convert2(string s, int nRows) {

        if (nRows <= 1)
            return s;

        const int len = (int)s.length();
        vector<string> str(nRows,"");

        int row = 0, step = 1;
        for (int i = 0; i < len; ++i)
        {
            str[row].push_back(s[i]);

            if (row == 0)
                step = 1;
            else if (row == nRows - 1)
                step = -1;

            row += step;
        }

        s.clear();
        for (int j = 0; j < nRows; ++j)
        {
            s.append(str[j]);
        }

        return s;
    }
};


int main() {

}