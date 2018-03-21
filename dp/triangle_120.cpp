//
// Created by YuXiao on 3/21/18.
//

#include <string>
#include <iostream>
#include <vector>
// https://leetcode.com/problems/triangle/description/
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        size_t num_length = triangle.size();
        int num[num_length] = {0};
        for (int i = 0; i < num_length; i++) {
            num[i] = triangle.at(num_length - 1).at(i);
        }

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                num[j] = triangle.at(i).at(j) + min(num[j], num[j + 1]);
            }
        }

        return num[0];
    }

    int minimum_total_top_down(vector<vector<int>> & triangle){
        if(triangle.size() == 0) return 0;
        size_t len = triangle.size();

        vector<vector<long>> cache(triangle.size()) ;
        for(int i=0;i< len;i++){
            cache[i]=vector<long>(len,LONG_MIN);
        }
        return dfs(triangle, 0, 0, 0, cache);

    }

    int dfs(vector<vector<int>>& triangle, int i_cur, int j_cur, int total, vector<vector<long>>& cache){
        int t_min = INT_MAX;
        if(cache[i_cur][j_cur] != LONG_MIN){
            t_min = static_cast<int>(cache[i_cur][j_cur]);
        }else if(i_cur == triangle.size() -1){
            t_min = triangle.at(i_cur).at(j_cur);
        }else {
            t_min = dfs(triangle,i_cur+1, j_cur, triangle.at(i_cur).at(j_cur), cache);
            int t_min_2 = dfs(triangle,i_cur+1, j_cur+1, triangle.at(i_cur).at(j_cur), cache);
            t_min = min(t_min, t_min_2);
        }
        cache[i_cur][j_cur] = t_min;
        return t_min + total;
    }
};

int main() {
    cout << "ee" << endl;
}