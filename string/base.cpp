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



void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

vector<string> split(const string &str, const string &delim) {
    vector<string> res;
    if ("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}

//// KMP table:
//
//    c a t a c b # b c a t a c
//
//    0 0 0 0 1 0 0 0 1 2 3 4 5
vector<int> get_KMP_table(string temp_str) {
    vector<int> table(temp_str.length());
    int j = 0, k = -1;
    table[0] = -1;
    while (j < temp_str.length() - 1) {
        if (k == -1 || temp_str[k] == temp_str[j]) {
            table[++j] = ++k;
        } else {
            k = table[k];
        }
    }
//        for(auto& letter:temp_str){
//            cout<<letter<<" ";
//        }
//        cout<<endl;
//        for (auto& item:table){
//            cout<<item << " ";
//        }
//        cout<<endl;
    return table;

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