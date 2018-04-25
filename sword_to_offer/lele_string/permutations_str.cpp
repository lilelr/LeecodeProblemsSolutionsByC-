//
// Created by YuXiao on 4/25/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.length() == 0) {
            return res;
        }

        unordered_set<string> tset;
//        help(str, str.length(), 0, res, tset);
        fun(res, str, 0, str.length());
        return res;

    }

    void fun(vector<string> &res, string str, int index, int n) {
        if (index == n - 1) {
            res.push_back(str);
        }

        unordered_set<char> us;
        sort(str.begin() + index, str.end());

        for (int i = index; i < n; i++) {
            if (us.find(str[i]) == us.end()) {
                us.insert(str[i]);
                swap(str[index], str[i]);
                fun(res, str, index + 1, n);
                swap(str[index], str[i]);
            }
        }
    }

    void help(string origin, int n, int index, vector<string> &res, unordered_set<string> &tset) {
        if (index == n) {
            if (tset.find(origin) == tset.end()) {
                tset.insert(origin);
                res.push_back(origin);
            }
        } else {
            for (int i = index; i < n; i++) {

                char temp = origin[i];
                origin[i] = origin[index];
                origin[index] = temp;

                help(origin, n, index + 1, res, tset);

                temp = origin[i];
                origin[i] = origin[index];
                origin[index] = temp;
            }
        }

    }
};


int main() {
    Solution s;
    string test_a = "abc";
    string test_b = "aa";
    vector<string> res = s.Permutation(test_b);
    for (string item:res) {
        cout << item << endl;
    }
}