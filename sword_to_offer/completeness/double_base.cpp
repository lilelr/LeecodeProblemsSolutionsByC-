//
// Created by YuXiao on 4/9/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool equal(double m1, double m2){
        if(abs(m1-m2) <0.0000001){
            return true;
        }
        return false;
    }

    /**
     *
     * @param base double
     * @param ex >=0
     * @return
     */
    double unsigned_int_power(double base, int ex){
        if(ex==0){
            return 1;
        }
        if(ex ==1){
            return base;
        }

        int pre = ex>>1; // 除以2, 6/2 = 3
        // 写出递推式 a^4 = (a^2) * (a^2)
        double res = unsigned_int_power(base,pre);
        res = res*res;
        if(ex & 0x1 ==1){ //ex 为奇数，还得乘多一个底数
            res *= base;
        }
        return res;
    }
    /**
     * 求以base 为底数，exponent 为指数的结果
     * @param base
     * @param exponent
     * @return
     */
    double Power(double base, int exponent) {
        if(equal(base,0) && exponent <0){
            return 0.0;
        }

        unsigned int abs_exponent;
        if(exponent <0){ // 指数小于0，先转为正，，最后转成分子式
            abs_exponent = (-exponent);
        }else{
            abs_exponent = exponent;
        }

        double res = unsigned_int_power(base, abs_exponent);
        if(exponent<0){
            res = 1.0/res;
        }
        return res;
    }
};


int main() {
    Solution s;

    double res = s.Power(4,-3);
    cout<<res<<endl;
}