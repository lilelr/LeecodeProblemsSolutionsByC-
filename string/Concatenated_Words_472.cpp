//
// Created by YuXiao on 5/22/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// 字典树+DFS https://leetcode.com/problems/concatenated-words/discuss/95644/102ms-java-Trie-+-DFS-solution.-With-explanation-easy-to-understand.
class Solution {
private:
    struct TrieNode {
        vector<TrieNode *> sons;
        bool is_end;

        TrieNode() {
            sons = vector<TrieNode *>(26, nullptr);
        }

    };



    void add_word(string &str, TrieNode *root) {
        TrieNode *cur = root;
        for (char &c:str) {
            if (cur->sons[c - 'a'] == nullptr) {
                cur->sons[c - 'a'] = new TrieNode();
            }
            cur = cur->sons[c - 'a'];
        }
        cur->is_end = true;
    }

public:

    bool test_word(const char chars[], int index, TrieNode *root, int count) {
        TrieNode *cur = root;
        int n = strlen(chars);
        for (int i = index; i < n; i++) {
            if (cur->sons[chars[i] - 'a'] == nullptr) {
                return false;
            }

            if (cur->sons[chars[i] - 'a']->is_end) {
                if (i == n - 1) {
                    return count >= 1;
                }

                if (test_word(chars, i + 1, root, count + 1)) {
                    return true;
                }
            }
            cur = cur->sons[chars[i] - 'a'];
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> res;
        int len = words.size();
        if (len == 0) return res;

        TrieNode *root = new TrieNode();
        for (string &word:words) {
            if (word.length() == 0) continue;
            add_word(word, root);
        }

        for (string &word:words) {
            if (word.length() == 0) {
                continue;
            }

            if (test_word(word.c_str(), 0, root, 0)) {
                res.push_back(word);
            }
        }
        return res;
    }


    // dp https://leetcode.com/problems/concatenated-words/discuss/95677/C++-772-ms-dp-solution
    vector<string> findAllConcatenatedWordsInADict_DP(vector<string> &words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j - i))) dp[j] = 1;
                }
                if (dp[n]) {
                    res.push_back(w);
                    break;
                }
            }
        }
        return res;
    }


};


int main() {
    Solution s;
    vector<string> test_words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat",
                                 "ratcatdogcat"};
    vector<string> res = s.findAllConcatenatedWordsInADict(test_words);
    for (auto &item:res) {
        cout << item << endl;
    }

    cout << strlen("abc") << endl;
    cout << sizeof("abc") << endl;
}