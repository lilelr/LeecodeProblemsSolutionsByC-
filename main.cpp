// https://www.cnblogs.com/skywang12345/p/3602162.html
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <list>


using namespace std;
class LFUCache{
private:
    int cap;
    int size;
    int min_freq;  // minFreq is the smallest frequency so far

    unordered_map<int, pair<int,int>> my_map; // {key to {value, frequency} }
    unordered_map<int, list<int>::iterator> map_iter; // {key, list iterator of fm }
    unordered_map<int, list<int> > fm;


public:
    LFUCache(int capacity){
        cap = capacity;
        size = 0;
    }

    int get(int key){
        if(my_map.count(key) == 0) return -1;

        fm[my_map[key].second].erase(map_iter[key]);
        my_map[key].second++;
        fm[my_map[key].second].push_back(key);
        map_iter[key] = --fm[my_map[key].second].end();

        if(fm[min_freq].size() == 0){
            min_freq++;
        }

        return my_map[key].first;
    }

    void put(int key, int value){
        if(cap <= 0 ) return;

        int store_value = get(key);
        if(store_value != -1){
            my_map[key].first = value;
            return;
        }

        if(size >= cap){
            my_map.erase(fm[min_freq].front());
            map_iter.erase(fm[min_freq].front());
            fm[min_freq].pop_front();
            size--;
        }

        my_map[key] = {value,1};
        fm[1].push_back(key);
        map_iter[key]  = --fm[1].end();
        min_freq = 1;
        size++;

    }
};
int main() {
//    vector<int> nums = {3,1,2,5};
//    quick_sort(nums,0,3);
//    for(auto& item:nums){
//        cout<<item<<": ";
//    }
//    return 0;
}