//https://blog.csdn.net/yanglingwell/article/details/68952342
#include <string>
#include <iostream>
#include <vector>

#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
//原
//        LeetCode: 44. Wildcard Matching
//2017年04月02日 15:33:49 杨领well 阅读数：908 标签： leetcode wildcard pattern matching  更多
//        个人分类： LeetCode LeetCode: 41-60
//所属专栏： 杨领well的 LeetCode 题解专栏
//        版权声明：本文由博主@杨领well发表在http://blog.csdn.net/yanglingwell，如果转载请注明出处。	https://blog.csdn.net/yanglingwell/article/details/68952342
//        LeetCode: 44. Wildcard Matching
//题目描述
//        Implement wildcard pattern matching with support for ‘?’ and ‘*’.
//
//‘?’ Matches any single character.
//‘*’ Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch(“aa”,”a”) → false
//isMatch(“aa”,”aa”) → true
//isMatch(“aaa”,”aa”) → false
//isMatch(“aa”, “*”) → true
//isMatch(“aa”, “a*”) → true
//isMatch(“ab”, “?*”) → true
//isMatch(“aab”, “c*a*b”) → false
//
//题目大意： 给定模式串 p, 匹配串 s。其中，p含有通配符 (Wildcard)。 ‘?’ 代表可以匹配任意一个字符， ‘*’ 代表可以匹配任意个数任意字符。 判断 p 串 和 s 串是否匹配。
//
//解题思路 — 动态规划
//        记s串的前i个字符和p串的前j个字符能否匹配为 dp[i][j]。
//如果模式串p和匹配串s都为空，则匹配成功， dp[0][0] = true;。
//如果模式串p为空，s串不为空， 则匹配失败， dp[i][0] = false, 其中 0 < i <= s.size()。
//如果模式串p不为空， s串为空，i > 0, 若 p[i-1] == '*' 则 dp[0][i] 的真值受 dp[0][i-1] 的影响。否则， dp[0][i] = false 。即，
//

using namespace std;

typedef long long LL;

#define M(a, b) memset(a,b,sizeof(a))

// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
typedef long long LL;

const int maxn = 0x3f3f3f3f;

/**
 *
 * @param s 待匹配字符串
 * @param p 模式字符串 含有 * ? *
 * @return 是否匹配
 */
bool isMatch(string s, string p) {

    vector<vector<bool>> dp;
    dp.resize(s.size() + 1);
    for (auto &vb : dp) vb.resize(p.size() + 1, false);
    dp[0][0] = true;

    for (int i = 1; i <= p.size(); ++i) { // # 匹配前面的一个字符1次或0次，？匹配1次， * 匹配0次或多次
        if (p[i - 1] == '*' || p[i-1]=='#') dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= p.size(); ++j) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j-1] == '#'){
                if(dp[i][j-1] == true || dp[i-1][j-1]==true){
                    dp[i][j] = true;
                }
            } else if (p[j - 1] == '*') {
                for (int k = 0; k <= i; ++k) {
                    if (dp[k][j - 1] == true) {
                        dp[i][j] = true;
                        break;
                    }
                }
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[s.size()][p.size()];
}

int main() {
    string str,pa;
    cin>>pa;
    cin>>str;

    bool res = isMatch(str,pa);
    if(res){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;

}
