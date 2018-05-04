
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
      int len = numbers.size();
        if(len<1){
            return false;
        }
        sort(numbers.begin(),numbers.end());

        int number_of_zero = 0;
        int number_of_gap = 0;
        for(int i=0;i<len && numbers[i]==0;i++){
            ++number_of_zero;
        }

        int small = number_of_zero;
        int big = small + 1;
        while (big < len){
            if(numbers[small] == numbers[big]){
                return false;
            }
            number_of_gap += numbers[big] - numbers[small] -1;
            small = big;
            ++big;
        }
        bool ans = (number_of_gap > number_of_zero) ? false : true;
        return ans;
    }
};