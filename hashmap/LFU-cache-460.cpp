
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

// https://leetcode.com/problems/lfu-cache/description/
// https://leetcode.com/problems/lfu-cache/discuss/94516/Concise-C++-O(1)-solution-using-3-hash-maps-with-explanation
class LFUCache {
    //minFreq is the smallest frequency so far
//The main idea is to put all keys with the same frequency to a linked list so the most recent one can be evicted;
//mIter stored the key's position in the linked list;
private:
    int cap;
    int size;
    int min_freq;  // minFreq is the smallest frequency so far
    unordered_map<int, pair<int, int>> m;// key to {value, freq}
    unordered_map<int, list<int>::iterator> m_iter; // key to list iterator of fm
    unordered_map<int, list<int>> fm; // freq to key list

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (m.count(key) == 0) return -1; // no such key
        fm[m[key].second].erase(m_iter[key]); // first delete
        m[key].second++; // frequency ++
        fm[m[key].second].push_back(key); // frequency map push_back
        m_iter[key] = --fm[m[key].second].end(); // record its index in the key list

        if (fm[min_freq].size() == 0) {
            min_freq++;
        }

        return m[key].first;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        int store_val = get(key);
        if (store_val != -1) {
            m[key].first = value;
            return;
        }

        if (size >= cap) { // size 只可能比cap 大1 时，即可size --
            m.erase(fm[min_freq].front()); // 取最小min_freq 双链表中的头元素
            m_iter.erase(fm[min_freq].front());
            fm[min_freq].pop_front();
            size--;
        }

        m[key] = {value, 1};
        fm[1].push_back(key); // fm[1] 为空的话，会自动创建<list>
        m_iter[key] = --fm[1].end();
        min_freq = 1; // 更新frequency 最小值为1
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */