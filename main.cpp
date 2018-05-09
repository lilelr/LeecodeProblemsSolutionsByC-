#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
// C++ 2ms solution beats 100% (a bit long but easy to understand)
// https://leetcode.com/problems/additive-number/discuss/123337/C++-2ms-solution-beats-100-(a-bit-long-but-easy-to-understand)
class Solution {
    bool isOk(string s1, string s2, string& s, int start, string& out)
    {
        if ( (s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0'))
            return false;
        out = StringAddition(s1, s2);
        if (strncmp(out.c_str(), s.substr(start).c_str(), out.length()) != 0)
            return false;
        return true;
    }
    string StringAddition(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            string s = s1;
            s1 = s2;
            s2 = s;
        }
        int prev = 0;
        int len1 = s1.length();
        int len2 = s2.length();
        int i = 0;
        while (i < len1)
        {
            int sum = s1[len1-i-1] + s2[len2-i-1] + prev - 2 * '0';
            s2[len2-i-1] = sum % 10 + '0';
            prev = sum / 10;
            i++;
        }

        if (prev == 0)
            return s2;
        //len2-i-1 is the index of next char in s2.
        while (len2 - i - 1 >= 0)
        {
            int sum = s2[len2 - i - 1] - '0' + prev;
            s2[len2 - i - 1] = sum % 10 + '0';
            prev = sum / 10;
            if (prev == 0)
                break;
            i++;
        }
        if (prev != 0)
        {
            return "1" + s2;
        }
        return s2;
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for( int i = 1; i <= 2*n/3-1; i++)
            for (int j = 0; j <= i - 1; j++)
            {
                string s1 = num.substr(0, j + 1);
                string s2 = num.substr(j + 1, i - j);
                int start = i+1;
                string s3;
                while (isOk(s1, s2, num, start,s3))
                {
                    s1 = s2;
                    s2 = s3;
                    start += s3.length();
                    if (start == num.length())
                        return true;
                }
            }
        return false;
    }
};