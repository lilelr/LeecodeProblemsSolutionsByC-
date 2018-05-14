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
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C++-128m-Solution-Real-O(1)-Solution

//There are two data member in the solution
//
//a vector nums
//        an unordered_map m
//The key of m is the val, the value of m is a vector contains indices where the val appears in nums.
//Each element of nums is a pair, the first element of the pair is val itself, the second element of the pair is an index into m[val].
//There is a relationship between nums and m:
//
//        m[nums[i].first][nums[i].second] == i;
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();

        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val)!= m.end();
        if(result){
            pair<int,int> last = nums.back();
            m[last.first][last.second] = m[val].back(); // 在map中，把last 的记录位置改为原 val 的记录位置
            nums[m[val].back()] = last;// 在vector 数组中，把last 的值放到原 val 的值位置上
            m[val].pop_back();
            if(m[val].empty()){
                m.erase(val);
            }
            nums.pop_back();
        }
        return result;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};