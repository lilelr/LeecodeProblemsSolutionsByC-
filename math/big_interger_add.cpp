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


// 大数相乘
// 先确定符号位，分两种情况，1 两个数都为负数或都为正数， 结果为正 2 一正一负， 结果为负数

string bigIntegerPlus(string res, string plusN) {

    string ret;
    if (res.length() < plusN.length()) {

        string tmp = res;
        res = plusN;
        plusN = tmp;
    }

    int len1 = res.length(), len2 = plusN.length();
    for (int i = len2 - 1; i >= 0; --i) {

        string tmp(len1, '0'); // 存放相乘的中间结果
        int goBit = 0;
        for (int j = len1 - 1; j >= 0; --j) {

            int mid = (res[j] - '0') * (plusN[i] - '0') + goBit;
            tmp[j] = mid % 10 + '0';
            goBit = mid / 10;
        }
        if (goBit != 0)
            tmp.insert(0, string(1, goBit + '0'));

        for (int m = 0; m < len2 - 1 - i; ++m)
            tmp.push_back('0'); // 补位

        // 相乘后就相加  大数相加
        if (i == len2 - 1)
            ret = tmp;
        else {

            int goBit2 = 0;
            string s(tmp.length() - ret.length(), '0');
            ret = s + ret;
            for (int m = tmp.length() - 1; m >= 0; --m) {

                int mid = (tmp[m] - '0') + (ret[m] - '0') + goBit2;
                ret[m] = mid % 10 + '0';
                goBit2 = mid / 10;
            }

            if (goBit2 != 0)
                ret.insert(0, string(1, goBit + '0'));
        }
    }

    // 去掉前导0
    while (ret.length() > 1 && ret[0] == '0') {
        ret.erase(0, 1);
    }

    return ret;
}

// 实现的是大数跟int类型的相除和求余，解题心得: 模拟手算的过程。需要注意的是。其中余数的存放要用long long存放比较好。因为如果采用int类型那么     rem = prem * 10/*向后退一位*/ + src[i] - '0';    这行代码可能会出现溢出问题。

// 注意符号的判断，一正一负，
// 注意除数是否为0
typedef long long LL;

void big_num_division(string &dividend, int divisor, char sign) {
    LL remainder = 0; // 存放新余数
    LL pre_remainder = 0; // 存放旧余数
    bool flag = true;
    int k = 0;
    char res[10000] = "";
    int len_di = dividend.length();
    for (int i = 0; i < len_di; i++) {
        remainder = pre_remainder * 10 + (dividend[i] - '0');

        if (remainder / divisor > 0 || remainder == 0) {
            res[k++] = remainder / divisor + '0';
            pre_remainder = remainder % divisor;
            flag = false;
        } else {
            pre_remainder = remainder;
            if (!flag) {
                res[k++] = '0';
            }
        }
    }
    if (sign == '%') {
        cout << pre_remainder << endl;
    } else {
//        for(int i=0;i<k;i++){
//            cout<<res[i];
//        }
        res[k] = '\0';
        string ans = res;
        cout << ans << endl;
    }
}
//int main(int argc, char** argv) {
//
//    char src[10000] = "";
//    int num;
//    char sign;
//    while (scanf("%s %c %d", src, &sign, &num) != EOF) {
//
//        bigDivision(src, num, sign);
//    }
//
//    return 0;
//}


int main() {

    string s1;
    string result;
    // 大数加法
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

//    string str1 = "123";
//    string str2 = "200";
//    if (str2 > str1) {
//        cout << "str2 bigger" << endl;
//    }

    //大数乘法
    // 大数除法
    string dividend = "134";
    int divisor = 12;
    big_num_division(dividend,divisor,'/');
    big_num_division(dividend,divisor,'%');
    return 0;
}