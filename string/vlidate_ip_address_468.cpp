//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;
// https://leetcode.com/problems/validate-ip-address/description/

// https://leetcode.com/problems/validate-ip-address/discuss/95552/My-Straightforward-C++-Solution
class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        string res = "Neither";
        if (IP.find(':') == string::npos) {
            while (getline(is, t, '.')) {
                ++cnt;
                if (cnt > 4 || t.empty() || t.size() > 3 || (t.size() > 1 && t[0] == '0')) {
                    return "Neither";
                }
                for (char c:t) {
                    if (c < '0' || c > '9') return "Neither";
                }
                int val = stoi(t);
                if (val < 0 || val > 255) return "Neither";
            }
            if (cnt == 4 && IP.back() != '.') {
                res = "IPv4";
            }

        } else {
            while (getline(is, t, ':')) {
                ++cnt;

                if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
                for (char c:t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";

                }
            }

            if (cnt == 8 && IP.back() != ':') {
                res = "IPv6";
            }
        }
        return res;

    }
};


int main() {

}