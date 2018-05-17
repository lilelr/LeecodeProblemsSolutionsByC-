//
// Created by YuXiao on 5/17/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
// https://leetcode.com/problems/count-the-repetitions/description/
// https://leetcode.com/problems/count-the-repetitions/discuss/95398/C++-solution-inspired-by-@70664914-with-organized-explanation
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size();
        int len2 = s2.size();
        vector<int> repeat_count(len2 + 1, 0);
        vector<int> next_index(len2 + 1, 0);

        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == len2) {
                        j = 0;
                        ++cnt;
                    }
                }
            }

            repeat_count[k] = cnt;
            next_index[k] = j;
            for (int start = 0; start < k; start++) {
                if (next_index[start] == j) {
                    int prefix_count = repeat_count[start];
                    int patter_count = (repeat_count[k] - repeat_count[start]) * ((n1 - start) / (k - start));
                    int suffix_count = repeat_count[start + (n1 - start) % (k - start)] - repeat_count[start];
                    return (prefix_count + patter_count + suffix_count) / n2;
                }
            }
        }
        return repeat_count[n1] / n2;
    }
};


int main() {

}