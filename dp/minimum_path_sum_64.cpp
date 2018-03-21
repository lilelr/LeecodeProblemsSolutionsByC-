//
// Created by YuXiao on 3/21/18.
//
#include "minimum_path_sum_64.h"

int main()
{
   Solution solution;
//    vector<vector<int>> grid(3);
//    vector<int> first_row{1,3,1};
//    grid[0] = first_row;
//    vector<int> second_row{1,5,1};
//    grid[1] = second_row;
//    vector<int> third_row{4,2,1};
//    grid[2] = third_row;
//    int result = solution.minPathSum(grid);
//    cout<<result<<endl;
//    vector<int> first_row{1,3,1};
//    grid[0] = first_row;

    vector<vector<int>> grid(2);
    vector<int> first_row{1,2,5};
    grid[0] = first_row;
    vector<int> second_row{3,2,1};
    grid[1] = second_row;
//    vector<int> third_row{4,2,1};
//    grid[2] = third_row;
    int result = solution.minPathSum(grid);
    cout<<result<<endl;
}