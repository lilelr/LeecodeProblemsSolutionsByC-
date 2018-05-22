
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
private:
    int cap;
    int size;
    int min_freq;
    unordered_map<int, pair<int, int>> m;// key to {value, freq}
    unordered_map<int, list<int>::iterator> m_iter; // key to list iterator of fm
    unordered_map<int, list<int>> fm; // freq to key list

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (m.count(key) == 0) return -1;
        fm[m[key].second].erase(m_iter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        m_iter[key] = --fm[m[key].second].end();

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
        fm[1].push_back(key);
        m_iter[key] = --fm[1].end();
        min_freq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */