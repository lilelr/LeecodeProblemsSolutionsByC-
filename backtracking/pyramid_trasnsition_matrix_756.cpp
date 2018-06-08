//
// Created by YuXiao on 6/7/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/pyramid-transition-matrix/description/
//https://leetcode.com/problems/pyramid-transition-matrix/discuss/113054/Java-solution-map-+-backtracking
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        map<string, vector<string>> mymap;

        for (string s:allowed) {
            string key = s.substr(0, 2);
            if (mymap.count(key) == 0) {
                mymap.insert({key, vector<string>()});
            }
            mymap[key].push_back(s.substr(2));
        }
        bool res = helper(bottom, mymap);
        return res;
    }

    bool helper(string &bottom, map<string, vector<string>> &mymap) {
        if (bottom.length() == 1) return true;
        for (int i = 0; i < bottom.length() - 1; i++) {
            if (mymap.count(bottom.substr(i, 2)) == 0) return false;
        }

        vector<string> ls;
        string temp_str;
        get_list(bottom, 0, temp_str, ls, mymap); // 获取每一行的可能匹配结果string 集合ls, temp_str 记录其中一种结果可能
        for (string &s:ls) {
            if (helper(s, mymap)) return true;
        }
        return false;
    }

    /**
     *
     * @param bottom 当前层的pyramid 字母序列
     * @param idx 当前层已匹配到pyramid 字母序列的下标
     * @param sb 记录一种满足mymap 要求的结果string
     * @param ls 所有可能结果的集合
     * @param mymap 匹配规则
     */
    void get_list(string &bottom, int idx, string sb, vector<string> &ls, map<string, vector<string>> &mymap) {
        if (idx == bottom.length() - 1) {
            ls.push_back(sb);
            return;
        }

        for (string &s: mymap[bottom.substr(idx, 2)]) {
            sb.append(s);
            get_list(bottom, idx + 1, sb, ls, mymap);
            // backtracking
            sb.erase(sb.length() - 1, 1);
        }
    }
};


int main() {

}