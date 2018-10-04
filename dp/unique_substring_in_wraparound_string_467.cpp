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
//https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95439/Concise-Java-solution-using-DP
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt_letter(26, 0);
        int max_length_cur = 0;
        int n = p.length();
        for (int i = 0; i < n; i++) {
            if (i > 0 && ((p[i] - p[i - 1] == 1) || (p[i - 1] - p[i] == 25))) {
                max_length_cur++;
            } else {
                max_length_cur = 1;
            }

            int index = p[i] - 'a';
            cnt_letter[index] = max(cnt_letter[index], max_length_cur); // dp function
        }

        int res = accumulate(cnt_letter.begin(), cnt_letter.end(), 0);
        return res;
    }
};


int main() {

}