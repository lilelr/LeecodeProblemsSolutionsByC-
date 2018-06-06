//
// Created by YuXiao on 6/6/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
// https://leetcode.com/problems/shopping-offers/description/
// https://leetcode.com/problems/shopping-offers/discuss/105212/Very-Easy-to-understand-JAVA-Solution-beats-95-with-explanation
using namespace std;
class Solution {

private:
    map<vector<int>, int> mymap;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mymap.count(needs)){
            return mymap[needs];
        }

        int res = INT_MAX;

        for(auto s : special){
            vector<int> new_needs(needs.begin(), needs.end());
            bool valid_special = true;
            for(int i=0;i<needs.size();i++){
                new_needs[i] -=s[i];
                if(new_needs[i] <0){
                    valid_special = false;
                    break;
                }
            }

            if(valid_special){
                res = min(res, s.back() + shoppingOffers(price, special,new_needs));
            }
        }
        int normal_price = 0;
        for(int i=0;i<needs.size();i++){
            normal_price += (price[i] * needs[i]);
        }
        res = min(res, normal_price);
        mymap[needs] = res;
        return mymap[needs];
    }
};

