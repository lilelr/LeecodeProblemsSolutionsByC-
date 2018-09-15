//
// Created by YuXiao on 3/27/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
// https://leetcode.com/problems/remove-invalid-parentheses/description/
using namespace std;

class Solution {
public:
    // 判断括号字符串是否成双成对
    bool is_valid(string s) {
        int count = 0;
        for (char item:s) {
            if (item == '(') {
                count++;
            }
            if (item == ')' && count-- == 0) {
                return false;
            }
        }
      return count==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.length() == 0) return vector<string>(1,"");
        set<string> visited; // 保存已经遍历过的字符串
        queue<string> queue; // 存放只包含括号的字符串
        queue.push(s);
        visited.insert(s);

        bool found = false;

        while (!queue.empty()) {
            s = queue.front();
            queue.pop();

            if (is_valid(s)) {
                res.push_back(s);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '(' && s[i] != ')') continue;
                // 忽略当前括号，提取字符串
                string t = s.substr(0, i) + s.substr(i + 1);

                if (visited.find(t) == visited.end()) {
                    queue.push(t);
                    visited.insert(t);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution solution;
        string test_str = "()())()";
        vector<string> res = solution.removeInvalidParentheses(test_str);
        for(auto str:res){
            cout<<str<<endl;
        }
}