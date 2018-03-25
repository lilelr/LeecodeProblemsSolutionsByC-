//
// Created by YuXiao on 3/22/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<int> ugly_vec;
        int i2=0;
        int i3=0;
        int i5=0;
        int count = 1;
        int next_item;
        ugly_vec.push_back(1);
        while (count < n){
            next_item = min(ugly_vec.at(i2)*2, ugly_vec.at(i3)*3);
            next_item = min(ugly_vec.at(i5)*5,next_item);
            if(next_item == ugly_vec.at(i2)*2){
                i2++;
            }

            if(next_item == ugly_vec.at(i3)*3){
                i3++;
            }

            if(next_item == ugly_vec.at(i5)*5){
                i5++;
            }
            ugly_vec.push_back(next_item);
            count++;

        }
        //        return ugly_vec.at(count-1);
        return *(ugly_vec.end()-1);
    }

    int ugly_number_priority_queue(int n){
        if(n==1) return 1;
        vector<int> factors{2,3,5};
        priority_queue<long,vector<long>, less<long>> queue;
        queue.push(1);
        long front_item;
        for(int i=0;i<n;i++){
            front_item = queue.top();
            queue.pop();
            for(int item: factors){
                long add_item = front_item*item;

            }
        }
    }


};