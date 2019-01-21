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
class Solution {
public:

    int recursive(int cur, vector<int> &ans) {
        if (ans[cur] != 0) {
            return ans[cur];
        } else {
            int left = cur / 2;
            int right = cur - left;
            int temp1 = recursive(left, ans) * recursive(right, ans);
            left--;
            right++;
            int temp2 = recursive(left, ans) * recursive(right, ans);
            int temp = max(temp1, temp2);

            ans[cur] = temp;
            return temp;
        }
    }

    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        vector<int> ans(n + 1, 0);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 3;
        int res = recursive(n, ans);
        return res;

    }


};

int main() {
    Solution s;

    cout << s.integerBreak(10) << endl;
    cout << s.integerBreak(6) << endl;
}