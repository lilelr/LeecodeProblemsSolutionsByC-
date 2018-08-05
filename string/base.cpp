//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
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
}