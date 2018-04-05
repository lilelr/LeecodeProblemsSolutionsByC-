//
// Created by YuXiao on 4/2/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 计算某个数的因子数，不包括1，和它本身
vector<int> get_factors(int n) {
    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            int quo = n / i;
            if (quo != i) {
                res.push_back(quo);
            }
        }
    }
    return res;
}

// c^2 = a^2+b^2
void square_of_three_numbers() {
    int n;
    cin>>n;
    int cnt=0;
    for(int x=1;x*x<=n;x++){
        int y = (int)sqrt(n-x*x);
        if(x*x + y*y == n){
            cnt++;
        }
    }
    cout<<cnt*4<<endl;
}
