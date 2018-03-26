#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//https://leetcode.com/problems/decode-ways/description/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.at(0)=='0'){
            return 0;
        }
        int* ways_to_decode = new int[s.length()+1];
        ways_to_decode[0] = 1;

        ways_to_decode[1] = 1;
        for(int i=1; i< s.length();i++){
            int curr = s.at(i) - '0';
            int prev = s.at(i-1) - '0';
            if(prev ==0 && curr==0 || (curr==0 && prev*10+curr>26) ){
                return 0;
            }

            else if(prev == 0 || (prev*10+curr)>26){
                ways_to_decode[i+1] = ways_to_decode[i];
            }else if(curr == 0){
                ways_to_decode[i+1] = ways_to_decode[i-1];
            }else{
                ways_to_decode[i+1] = ways_to_decode[i]+ways_to_decode[i-1];
            }
        }
        return ways_to_decode[s.length()];
    }
};


int main() {
    Solution solution;
    int result = solution.numDecodings("1234");
    cout<<result<<endl;

}