//
// Created by YuXiao on 4/11/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if( array.size() ==0) return false;
        int rows = array.size();
        int cols = array[0].size();

        bool found= false;

        int row = 0;
        int column = cols-1;

        while (row < rows && column >=0 ){
            if(array[row][column] == target){
                found = true;
                return found;
            }
            else if(array[row][column] > target){
                --column;
            }else{
                ++row;
            }
        }
        return found;

    }
};