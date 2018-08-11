
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:

};


int main() {
   bitset<10> b;
    b[1] = 1;
    b[6] = 1;
    b[9] = 1;
    cout<<b.count()<<endl;
    cout<<b.size()<<endl;
    if(b.test(9)){
        cout<<"true"<<endl;
    }
    b.set(4,1);
    for(int i=b.size()-1;i>=0;i--){
        cout<<b[i];

    }

    cout<<endl;
    b.flip();
    cout<<b<<endl;
    unsigned long c = b.to_ulong();
    cout<<c<<endl;
    int d = c;
    cout<<d<<endl;
}