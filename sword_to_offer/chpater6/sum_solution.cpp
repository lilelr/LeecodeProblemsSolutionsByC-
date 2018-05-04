
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

class A;
A* my_array[2];
class A{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

class B: public A{
public:
    virtual unsigned int Sum(unsigned int n){
        return my_array[!!n]->Sum(n-1)+n;
    }
};

class Solution {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        my_array[0] = &a;
        my_array[1] = &b;
        int res = my_array[1]->Sum(n);

        return res;
    }
};


int main() {

}