//
// Created by YuXiao on 4/11/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    void printMatrixIncircle(vector<vector<int>> matrix, int rows, int cols, int start, vector<int> &res) {
        int endX = cols - 1 - start;
        int endY = rows - 1 - start;
        //  从左到右打印一行
       for(int i=start;i<=endX;i++){
           int number = matrix[start][i];
           res.push_back(number);
       }
        // 从上到下打印一行
        if (start < endY) {
         for(int i=start+1;i<=endY;i++){
             int number = matrix[i][endX];
             res.push_back(number);
         }
        }

        // 从右到左打印一行
        if (start < endX && start < endY) {
          for(int i=endX-1;i>=start;i--){
              int number  = matrix[endY][i];
              res.push_back(number);
          }
        }

        // 从下到上打印一行
        if (start < endX && start < endY - 1) {
            for(int i=endY-1;i>start;i--){
                int number = matrix[i][start];
                res.push_back(number);
            }
        }

    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        while (cols > start*2 && rows > start*2){
            printMatrixIncircle(matrix,rows,cols,start,res);
            ++start;
        }

        return res;
    }
};


int main() {
    vector<vector<int>> matrix(4);
    for(int i=0;i<4;i++){
        matrix[i] = vector<int>(4);
    }
    matrix[0] = {1,2,3,4};
    matrix[1] = {5,6,7,8};
    matrix[2] = {9,10,11,12};
    matrix[3] = {13,14,15,16};
    Solution s;
    vector<int> res = s.printMatrix(matrix);
    for(int cur:res){
        cout<<cur<<endl;
    }

}