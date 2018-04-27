
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef multiset<int, greater<int>> int_set;
typedef multiset<int, greater<int>>::iterator set_iterator;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()<k || k<1){
            return vector<int>();
        }
        vector<int> ans(k);

        int_set tset;
        vector<int>::const_iterator iter = input.begin();
        for(;iter!= input.end();iter++){
            if(tset.size()<k){
                tset.insert(*iter);
            }else{
                set_iterator iter_greatest = tset.begin();
                if(*iter < *(tset.begin())){
                    tset.erase(iter_greatest);
                    tset.insert(*iter);
                }
            }
        }
        copy(tset.begin(),tset.end(),ans.begin());
        return ans;

    }
};


int main() {

    vector<int> input = {4,5,7,1,2,3};
    Solution s;
    vector<int> res = s.GetLeastNumbers_Solution(input,3);
    for(int item:res){
        cout<<item<<endl;
    }

}