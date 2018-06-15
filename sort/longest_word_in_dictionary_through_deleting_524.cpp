#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>

using namespace std;

class Solution {
/*
*   1. sort the vector from long to short and same length sort lexicographically.
*   2. check each string from start to end of the vector.
*/
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), compare);
        for (auto str : d) {
            if (check(s, str)) return str;
        }
        return "";
    }

    // return true if s can convert to now by deleting some characters.
    bool check(string s, string now) {
        for (int i = 0, j = 0; i < now.size(), j < s.size();) {
            if (now[i] == s[j]) {
                i++;
                j++;
            }else j++;
            if (i == now.size()) return true;
        }
        return false;
    }

    bool static compare(string a, string b) {
        return a.size() == b.size() ? a < b : a.size() > b.size();
    }
};