#include <iostream>
#include <string>

using namespace std;
// https://www.cnblogs.com/findumars/p/4684361.html
// 高精度问题之大数求幂，解题思路: 因为做了大数相加 ，这题也就没什么好思考的。不同之处就是先去掉小数点，计算结果后在适当位置插入小数点即可。这个算法可以计算更大的数。但必须包含小数点。。。。。。
// 求幂  思路: 先变成整数相乘   然后根据小数的位数 结合幂  算出小数点该结果字符串的位置 即可

string bigIntegerPlus(string src, string num) {

    string tmp = src;
    for (int i = num.length() - 1; i >= 0; --i) {

        string mid(tmp.length(), '0');
        int goBit = 0;
        for (int j = tmp.length() - 1; j >= 0; --j) {

            int tm = goBit + (tmp[j] - '0') * (num[i] - '0');
            mid[j] = tm % 10 + '0';
            goBit = tm / 10;
        }

        for (int q = num.length() - 1; q > i; --q)
            mid.push_back('0');
        if (goBit != 0)
            mid.insert(0, string(1, (char) goBit + '0'));

        // 加法运算
        if (i == num.length() - 1)
            src = mid;
        else {

            goBit = 0;
            string s(mid.length() - src.length(), '0');
            src = s + src;
            for (int j = mid.length() - 1; j >= 0; --j) {

                int tm = (mid[j] - '0') + (src[j] - '0') + goBit;
                src[j] = tm % 10 + '0';
                goBit = tm / 10;
            }

            if (goBit != 0)
                src.insert(0, string(1, (char) goBit + '0'));
        }
    }
    return src;
}


//输入12. 2
// 144.
int main() {

    string str;
    while (getline(cin, str)) {

        // 分割出待积数 和 幂  以及小数点位置
        int i = 0;
        int index = 0;// 小数位置
        int count = 0;//幂次数
        string num;
        while (i < str.length()) {

            if (str[i] != ' ') {

                if (str[i] == '.')
                    index = i;
                else
                    num.push_back(str[i]);
                ++i;
                continue;
            }
            while (!isdigit(str[i]))
                ++i;

            if (i + 1 == str.length())
                count = str[i] - '0';
            else
                count = (str[i] - '0') * 10 + str[i + 1] - '0';
            break;
        }

        index = num.length() - index;

        string res = num;
        for (int i = 0; i < count - 1; ++i) {

            res = bigIntegerPlus(res, num);
        }
        index = index * count;

        res.insert(res.length() - index, string("."));

        while (res.length() > 1 && res[0] == '0')
            res.erase(0, 1);

        for (int i = res.length() - 1; i >= 0; --i) {

            if (res[i] == '0')
                res.erase(i, i + 1);
            else
                break;
        }
        cout << res << endl;
    }

    return 0;
}