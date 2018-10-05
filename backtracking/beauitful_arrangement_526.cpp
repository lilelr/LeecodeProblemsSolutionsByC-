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
// https://leetcode.com/problems/beautiful-arrangement/description/
// https://leetcode.com/problems/beautiful-arrangement/discuss/99721/12-ms-Java-Backtracking-sulotion
class Solution {
public:
    int cnt;

    int countArrangement(int N) {
        cnt = 0;
        bool visited[N + 1] = {false};
        // The trick is: Arrange the values starting from the end of the array.
        dfs(N, N, visited);
        return cnt;
    }

    /**
     *
     * @param n input number
     * @param k current number k
     * @param visited
     */
    void dfs(int n, int k, bool visited[]) {
        if (k == 0) {
            cnt++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] || k % i != 0 && i % k != 0) {
                continue;
            }
            visited[i] = true; // 回溯
            dfs(n, k - 1, visited);
            visited[i] = false;// 回溯
        }
    }
};

int main() {

}