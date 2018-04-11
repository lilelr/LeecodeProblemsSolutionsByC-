//
// Created by YuXiao on 4/11/18.
//

class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int cache1 = 1;
        int cache2 = 2;
        int res;
        for (int i = 3; i <= number; i++) {
            res = cache1 + cache2 ;
            cache1 = cache2;
            cache2 = res;
        }
        return res;
    }
};