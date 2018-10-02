//https://leetcode.com/problems/complex-number-multiplication/description/
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
//        stringstream aa(a), bb(b), ans;
//        aa >> ra >> buff >> ia >> buff;
//        bb >> rb >> buff >> ib >> buff;
//        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
//

        stringstream aa(a),bb(b), ans;
        aa>> ra >> buff >> ia>>buff;
        bb>>rb>>buff>>ib>>buff;
        ans<< ra*rb - ia*ib <<"+"<< ra*ib+rb*ia<<"i";
        return ans.str();
    }

    string complexNumberMultiply_sscanf_sprintf(string a, string b) {
        int ar, ai;
        int br, bi;
        char buf[256];

        sscanf(a.c_str(), "%d+%di", &ar, &ai);
        sscanf(b.c_str(), "%d+%di", &br, &bi);

        sprintf(buf, "%d+%di", ar*br - ai*bi, ar*bi + br*ai);

        return string(buf);
    }
};


int main() {

}