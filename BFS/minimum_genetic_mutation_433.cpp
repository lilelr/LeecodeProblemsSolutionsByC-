#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;
//https://leetcode.com/problems/minimum-genetic-mutation/description/
class Solution {
private:
    bool mutatedFrom(string from, string to) {
        int result = 0;
        for (int i = 0; i < from.size(); i++) {
            if (from[i] != to[i]) {
                result += 1;
                if (result > 1) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> visited;
        for (string gene : bank) {
            visited[gene] = false;
        }

        queue<string> bfs;
        bfs.push(start);
        visited[start] = true;
        int step = 0;
        while (!bfs.empty()) {
            int length = bfs.size(); // 获取当前queue 的size
            for (int i = 0; i < length; i++) {
                string& cur = bfs.front();
                bfs.pop(); // 一个一个出队

                if (cur == end) {
                    return step;
                }

                for (string gene : bank) {
                    if (!visited[gene] && mutatedFrom(cur, gene)) {
                        bfs.push(gene);
                        visited[gene] = true;
                    }
                }
            }
            step += 1;
        }
        return -1;
    }

};


int main() {

}