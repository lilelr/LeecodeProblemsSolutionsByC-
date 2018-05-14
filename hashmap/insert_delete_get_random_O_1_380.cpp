//
// Created by YuXiao on 5/14/18.
//

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

class RandomizedSet {
public:
  RandomizedSet(){

  }
    bool insert(int val){
        if(m.find(val)!=m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size()-1;
        return true;
    }

    bool remove(int val){
        if(m.find(val)==m.end()) return false;
        int last = nums.back(); // 取 nums 的最后一个元素last ， 与要删除的val 置换, 此时 last 元素在nums中的位置已变为 原来val 的位置，所以要更新 map 中 last 元素的val 值
        m[last] = m[val]; // map 中的置换, 把 m[va] 的值赋给 m[last]
        nums[m[val]] = last;
        nums.pop_back(); // 弹出最后一个元素
        m.erase(val); // 删除val
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int,int> m;
};