//
// Created by YuXiao on 6/3/18.
//
// https://leetcode.com/problems/falling-squares/description/

// https://leetcode.com/problems/falling-squares/discuss/112678/Treemap-solution-and-Segment-tree-(Java)-solution-with-lazy-propagation-and-coordinates-compression
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
class SegmentTree{
public:
    SegmentTree(int N) {
        this->N = N;
        int n = (1 << ((int) ceil(log(N) / log(2) + 1)));
        tree = vector<int>(n, 0);
        lazy = vector<int>(n, 0);
    }

    int query(int L, int R) {
        return queryUtil(1, 0, N - 1, L, R);
    }

    int queryUtil(int index, int s, int e, int L, int R) {
        if (lazy[index] != 0) {
            int update = lazy[index];
            lazy[index] = 0;
            tree[index] = max(tree[index], update);
            if (s != e) {
                lazy[2 * index] = max(lazy[2 * index], update);
                lazy[2 * index + 1] = max(lazy[2 * index + 1], update);
            }
        }
        if ( s > e || s > R || e < L) {
            return 0;
        }
        if (s >= L && e <= R) {
            return tree[index];
        }
        int mid = s + (e - s)/2;
        return max(queryUtil(2 * index, s, mid, L, R) , queryUtil(2 * index + 1, mid + 1, e, L, R));
    }

    void update(int L, int R, int h) {
        updateUtil(1, 0, N - 1, L, R, h);
    }

    void updateUtil(int index, int s, int e, int L, int R, int h) {
        if (lazy[index] != 0) {
            int update =lazy[index];
            lazy[index] = 0;
            tree[index] = max(tree[index], update);
            if (s != e) {
                lazy[2 * index] = max(lazy[2 * index], update);
                lazy[2 * index + 1] = max(lazy[2 * index + 1], update);
            }
        }
        if ( s > e || s > R || e < L) {
            return ;
        }
        if (s >= L && e <= R) {
            tree[index] = max(tree[index], h);
            if (s != e) {
                lazy[2 * index] = max(lazy[2 * index], h);
                lazy[2 * index + 1] = max(lazy[2 * index + 1], h);
            }
            return ;
        }
        int mid = s + (e -s) /2;
        updateUtil(2 * index, s, mid, L, R, h);
        updateUtil(2 * index+ 1, mid + 1, e, L, R, h);
        tree[index] = max(tree[2 * index], tree[2*index + 1]);
    }

private:
    vector<int> tree;
    vector<int> lazy;
    int N;
};

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size();
        map<int, int> cc = coorCompression(positions);
        int best = 0;
        vector<int> res;
        SegmentTree *tree = new SegmentTree(cc.size());
        for (auto pos: positions) {
            int L = cc[pos.first];
            int R = cc[pos.first + pos.second - 1];
            int h = tree->query(L, R) + pos.second;
            tree->update(L, R, h);
            best = max(best, h);
            res.push_back(best);
        }
        return res;
    }

private:
    map<int, int> coorCompression(vector<pair<int, int>> &positions) {
        set<int> sets;
        for (auto pos : positions) {
            sets.insert(pos.first);
            sets.insert(pos.first + pos.second - 1);
        }
        vector<int> list(sets.begin(), sets.end());
        sort(list.begin(), list.end());
        map<int, int> maps;
        int t = 0;
        for (int pos: list) {
            maps[pos] = t++;
        }
        return maps;
    }
};