//
// Created by YuXiao on 6/10/18.
//

//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
// https://leetcode.com/problems/find-and-replace-in-string/description/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> sorted;
        for (int i = 0 ; i < indexes.size(); i++) sorted.push_back(make_pair(indexes[i], i));
        sort(sorted.rbegin(), sorted.rend());
        for (auto ind : sorted) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (S.substr(i, s.length()) == s) S = S.substr(0, i) + t + S.substr(i + s.length());
        }
        return S;
    }
};


int main() {
        string test_s = "abcd";
        vector<int> test_indexes= {0,2};
        vector<string> test_sources = {"a","cd"};
        vector<string> test_targets = {"eee","ffff"};
       Solution s;
       string res = s.findReplaceString(test_s,test_indexes,test_sources,test_targets);


}