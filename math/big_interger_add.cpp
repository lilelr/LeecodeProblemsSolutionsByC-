//
// Created by YuXiao on 5/2/18.
//

#include <iostream>
#include <string>

using namespace std;

// 实现两个正的大数相加  结果存放在result中
// 如果两个数符号不一致，分三类：1 两个正数 2 一正一负  3 两个负数
// 对于一正一负，先确定结果符号，首先比较字符串长度，长度大的一方的符号位即为结果的符号位；若字符串长度相等，字符串比较大小，大的一方的符号位作为结果的符号位

void big_integer_add(string &result, string add) {
    int len_r = result.size();
    int len_a = add.size();
    if (len_r < len_a) {
        swap(result, add);
    }
    len_r = result.size();
    len_a = add.size();
    string tmp(len_r - len_a, '0');
    add = tmp + add;

    int pre = 0;
    for (int i = len_a - 1; i >= 0; i--) {
        int cur = (result[i] - '0') + (add[i] - '0') + pre;
        result[i] = '0' + (cur % 10);
        pre = cur / 10;
    }
    if (pre != 0) {
        result.insert(0, string(1, (char) (pre + '0')));
    }
}


int main() {

    string s1;
    string result;
//    while (cin >> result >> s1) {
//
//        if (s1 == "0") {
//
//            cout << result << endl;
//            break;
//        }
//        big_integer_add(result, s1);
//        cout << result << endl;
//    }

    string str1 = "123";
    string str2 = "200";
    if(str2 > str1){
        cout<<"str2 bigger"<<endl;
    }
    return 0;
}