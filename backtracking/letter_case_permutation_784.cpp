#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

using namespace std;
//https://leetcode.com/problems/letter-case-permutation/discuss/119529/C++-backtrack-solution-with-xor-for-case-toggling
class Solution {
public:
    void permute (string S, vector<string>& result, int index)
    {

        //  cout <<S << " ";
        result.push_back(S);

        if(index >= S.size())
            return;

        for (int i = index ; i < S.size(); i++)
        {
            if (isalpha(S[i])) // 字母
            {
                //For Toogling the case of letter, xor with 32 beacuse letters are in such a way that toggling the 6th LSB will change its case from lower to upper and vice verse
                S[i] ^= 32;// 回溯 小写变大写，大写变小写
                permute (S, result, i+1);
                S[i] ^= 32;// 回溯
            }
        }
    }

    vector<string> letterCasePermutation(string S)
    {
        vector<string> result;
        permute(S, result, 0);
        return result;
    }
};

int main() {

}