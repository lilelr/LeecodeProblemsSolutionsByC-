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
        this->N = N; // 叶子节点个数
        int n = (1 << ((int) ceil(log(N) / log(2) + 1))); // 总的节点个数
        tree = vector<int>(n, 0); // 构造线段树的数据结构
        lazy = vector<int>(n, 0); // 延迟增量值
    }

    int query(int L, int R) { // lazy 意思 查询的时候才更新区间高度，update的时候不更新
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

    void update(int L, int R, int h) { // lazy 意思 查询的时候才更新区间高度，update的时候不更新
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
        SegmentTree *tree = new SegmentTree(cc.size()); // 构造一棵线段树，叶子节点个数为cc.size()
        for (auto pos: positions) {
            int L = cc[pos.first]; // 正方形的左上角有和右上角的x坐标区间 [L,R]
            int R = cc[pos.first + pos.second - 1];
            int h = tree->query(L, R) + pos.second;
            tree->update(L, R, h); // [L, R] 区间高度更新
            best = max(best, h); // 当前的最高度
            res.push_back(best); // 加入结果集
        }
        return res;
    }

private:
    // 坐标重叠放在一起，作高度压缩，返回x坐标集合 ,以便统计区间个数
    map<int, int> coorCompression(vector<pair<int, int>> &positions) {
        set<int> sets;
        for (auto pos : positions) {
            sets.insert(pos.first); // pos.first 正方形 起始左上角x坐标， pos.second正方形长度
            sets.insert(pos.first + pos.second - 1); // pos.first + pos.second -1 正方形右上角坐标 [pos.first, pos.first+pos.second-1]
        }
        vector<int> list(sets.begin(), sets.end());
        sort(list.begin(), list.end()); // 坐标排序
        map<int, int> maps;
        int t = 0;
        for (int pos: list) {
            maps[pos] = t++; // 记录x坐标点的在在原始坐标出现的次数
        }
        return maps;
    }
};