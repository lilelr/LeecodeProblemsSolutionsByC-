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
    static bool comp(int a, int b){
        string A="";
        string B="";
        A+=to_string(a);
        A+=to_string(b);
        B+=to_string(b);
        B+=to_string(a);
        return A<B;
    }

    string PrintMinNumber(vector<int> numbers) {
        string res="";
        sort(numbers.begin(),numbers.end(),comp);
        for(int i=0;i<numbers.size();i++){
            res+=to_string(numbers[i]);
        }
        return res;
    }

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
        // str index 到末尾排序
        sort(str.begin() + index, str.end());

        for (int i = index; i < n; i++) {
            if (us.find(str[i]) == us.end()) {
                us.insert(str[i]);
                // 交换 当前index 值与后面的 str[i] 值逐一交换
                swap(str[index], str[i]);
                fun(res, str, index + 1, n);
                swap(str[index], str[i]);    // 回溯
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
    vector<string> res = s.Permutation(test_a);
    for (string item:res) {
        cout << item << endl;
    }
}