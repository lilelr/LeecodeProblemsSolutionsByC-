//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:

};

string convertToString(double x){
    ostringstream o;
    if(o<<x){
        return o.str();
    }
    return "";
}

double convertFromString(const string& s){
    istringstream i(s);
    double x;
    i>>x;
    return x;
}
int main() {
 char b[10];
    string a;
    sprintf(b,"%d",1975);
    a = b;
    string cc = convertToString(3);
    cout<<cc<<endl;
    string dd = "3.2";
    double p = convertFromString(dd);
    cout<<p<<endl;

    string str1;
    str1 = "abc123456";
    str1.replace(0,3,"good");
    cout<<str1<<endl;

    string str2 = "cat dog cat";
    string str3 = "cat";

    cout<<str2.compare(str3)<<endl;

    std::vector<int> myvector;

    // set some values:
    for (int i=1; i<10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

    std::reverse(myvector.begin(),myvector.end());    // 9 8 7 6 5 4 3 2 1

    reverse(str3.begin(), str3.end());
    cout<<str3<<endl;
}