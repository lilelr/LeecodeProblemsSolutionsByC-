
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
    /**
     * 最长有效的括号长度
     * @param s
     * @return
     */
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0 || len == 1) { return 0; }
        stack<int> mystack;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                mystack.push(i); // stack 中记录的是下标
            } else { // s[i] = ')'
                if (mystack.empty()) {
                    // 为空，加入
                    mystack.push(i);
                    continue;
                }
                // 不为空
                // 判断栈顶元素是否是左括号
                char cur = s[mystack.top()];
                if (cur == '(') { // 从28行可知，构成一对有效对
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