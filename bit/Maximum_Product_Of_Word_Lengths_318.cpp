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
//https://leetcode.com/problems/maximum-product-of-word-lengths/
using namespace std;

class Solution {
public:
    bool has_common_letter(string &word1, string &word2) {
        vector<bool> aph(26, false);
        for (char &item:word1) {
            aph[item - 'a'] = true;
        }

        for (char &b:word2) {
            if (aph[b - 'a']) {
                return true;
            }
        }
        return false;

    }

    int maxProduct(vector<string> &words) {
        int n = words.size();
        int ma = 0;
        for (int i = 0; i < n; i++) {
            int cur_len = words[i].length();
            for (int j = i + 1; j < n; j++) {
                if (!has_common_letter(words[i], words[j])) {
                    int j_len = words[j].length();
                    ma = max(ma, cur_len * j_len);
                }
            }
        }
        return ma;
    }

    int maxProduct2(vector<string> &words) {
        vector<int> mask(words.size());
        int result = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j)
                if (!(mask[i] & mask[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }
        return result;
    }


};

int main() {
    Solution s;
//    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    int res = s.maxProduct(words);
    cout << res << endl;
}