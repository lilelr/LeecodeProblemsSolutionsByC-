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

// https://leetcode.com/problems/combinations/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;

        combineHelper(n, k, path, result);
        return result;
    }

    void combineHelper(int n, int k, vector<int> &path, vector<vector<int>> &result) {
        if (0 == k) {
            result.push_back(path);
            return;
        }

        if (k > n) return;

        //not pick n
        combineHelper(n - 1, k, path, result);
        //pick n
        path.insert(path.begin(), n);
        combineHelper(n - 1, k - 1, path, result);
        path.erase(path.begin()); //回溯，清空 path 的第一个元素，方便下一次插入新的元素
    }
};

int main() {

}