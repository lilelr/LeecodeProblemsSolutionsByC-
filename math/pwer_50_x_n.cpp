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

class Solution {
    // https://leetcode.com/problems/powx-n/discuss/19571/My-answer-using-bit-operation-(C%2B%2B-implementation)

    //In bit format and for a unsigned number, the number is represented as k0*2^0 + k1*2^1 + ... +k31*2^31. Therefore, once we know the pow(x,2^0), pow(x,2^1), ..., pow(x,2^31), we can get pow(x,n). And pow(x,2^m) can be constructed easily as pow(x,2^m) = pow(x,2^(m-1)*pow(x,2^(m-1).
public:
    double pow(double x, int n) {
        if (n < 0) { // n is negative
            x = 1.0 / x;
            n = -n;
        }

        unsigned int m = n;
        double tbl[32] = {0};
        double res = 1;
        tbl[0] = x;
        for (int i = 1; i < 32; i++) {
            tbl[i] = tbl[i - 1] * tbl[i - 1];
        }
        for (int i = 0; i < 32; i++) {
            if (m & (0x1 << i)) {
                res *= tbl[i];
            }
        }
        return res;
    }

    double pow_divide_conquer(double x, int m) {
        double temp = x;
        if (m == 0) {
            return 1;
        }
        temp = pow_divide_conquer(x, m / 2);

        if (m % 2 == 0) {
            return temp * temp;
        } else {
            if (m > 0) {
                return x * temp * temp;
            } else {
                return (temp * temp) / x;
            }

        }

    }

};

int main() {

}