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
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if(matrix.empty()) return false;
//        int m = matrix.size();
//        if(m==0) return false;
//        int n = matrix[0].size();
//        vector<int> tail;
//        for(int i=0;i<m;i++){
//            tail.push_back(matrix[i][n-1]);
//        }
//        int index = lower_bound(tail.begin(),tail.end(),target) - tail.begin();
//        if(index == m) return false;
//        bool res = binary_search(matrix[index].begin(), matrix[index].end(), target);
//        return res;
//    }

// top  right
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = matrix[0].size() - 1;
        for (int i = 0, j = n; i < matrix.size(), j > 0;) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }


};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{}};
    matrix = {{1,  3,  5,  7},
              {10, 11, 16, 20},
              {23, 30, 34, 50}};
    cout << s.searchMatrix(matrix, 1) << endl;
    cout << s.searchMatrix(matrix, 3) << endl;

}