
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/longest-valid-parentheses/description/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0 || len == 1) { return 0; }
        stack<int> mystack;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                mystack.push(i); // stack 中记录的是下标
            } else {
                if (mystack.empty()) {
                    mystack.push(i);
                    continue;
                }
                char cur = s[mystack.top()];
                if (cur == '(') {
                    mystack.pop();
                    int peek_val = mystack.empty() ? -1 : mystack.top();
                    ans = max(ans, i - peek_val);
                } else {
                    mystack.push(i);
                }
            }
        }
        return ans;
//        cout<<ans<<endl;
    }
};


int main() {
    Solution s;
    string str = "(()";
//    string str = ")()())";

    int ans = s.longestValidParentheses(str);
    cout << ans << endl;
}