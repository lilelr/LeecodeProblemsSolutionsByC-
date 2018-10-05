#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;
// https://leetcode.com/problems/palindrome-partitioning/discuss/41963/Java:-Backtracking-solution.
class Solution {
public:
    vector<vector<string>> res;// 所有可能的结果集的集合
    vector<string> cur_vec; // 一个可能的结果集
    vector<vector<string>> partition(string s) {

    back_track(s,0);
        return res;
    }

    /**
     *
     * @param s 字符串
     * @param l 开始位置
     */
    void back_track(string s, int l){
        if(cur_vec.size() > 0 && l>=s.length()){
            vector<string> r = cur_vec;
            res.push_back(r);
        }

        for(int i=l;i<s.length();i++){
                if(is_palindrome(s,l,i)){ // 是回文
                    cur_vec.push_back(s.substr(l,i+1-l));
//                    if(l==i){
//                        cur_vec.push_back(s[i]+"");
//                    }else{
//                        cur_vec.push_back(s.substr(l,i+1));
//                    }

                    back_track(s,i+1);
                    cur_vec.erase(cur_vec.end()-1); // 回溯
                }
        }
    }

    /**
     * 判断输入的字符串[l,r] 区间是否是回文
     * @param str
     * @param l
     * @param r
     * @return
     */
    bool is_palindrome(string str, int l,int r){
        if(l==r) return true;
        while (l<r){
            if(str[l]!=str[r])return false;
            l++;
            r--;
        }
        return true;

    }
};

int main() {

}