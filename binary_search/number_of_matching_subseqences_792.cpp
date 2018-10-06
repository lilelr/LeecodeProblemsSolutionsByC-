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
class Solution {
public:
    int numMatchingSubseq (string S, vector<string>& words) {
        vector<vector<int>> alpha(26);
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            alpha[S[i]-'a'].push_back(i);
        }

        int res = 0;
        for(const auto& word:words){
            int x = -1;
            bool found = true;

            for(char c:word){
                auto it = upper_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),x);
                if(it==alpha[c-'a'].end()) {
                    found = false;
                }else{
                    x = *it;
                }
            }
            if(found) res++;
        }

        return res;
    }

};

int main() {

}