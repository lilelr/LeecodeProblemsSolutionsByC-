
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
typedef long long LL;

class Solution {
public:
    enum Status {
        VALID = 0, INVALID
    };
    int res_status = VALID;

    int StrToInt(string str) {
        res_status = INVALID;
        LL num = 0;
        const char *cstr = str.c_str();
        if (cstr != NULL && *cstr != '\0') {
            int minus = 1;
            if (*cstr == '-') {
                minus = -1;
                cstr++;
            } else if (*cstr == '+') {
                cstr++;
            }

            while (*cstr != '\0') {
                if (*cstr > '0' && *cstr < '9') {
                    res_status = VALID;
                    num = (num << 1) + (num << 3) + ((*cstr) & 0xf);
                    cstr++;
                    if (((minus > 0) && (num > 0x7FFFFFFF)) || ((minus < 0) && (num > 0x80000000))) {
                        res_status = INVALID;
                        num = 0;
                        break;
                    }
                } else {
                    res_status = INVALID;
                    num = 0;
                    break;
                }

            }

            if (res_status == VALID) {
                num = num * minus;
            }
        }
        return (int) num;

    }

};


int main() {
      char a=1;
      int b = a & 0xf;
    cout<<b<<endl;
}