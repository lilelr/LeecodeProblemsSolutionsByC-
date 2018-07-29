//
// Created by YuXiao on 3/27/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Definition for undirected graph.
    struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;

        UndirectedGraphNode(int x) : label(x) {};
    };

    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &my_map) {
        if (node == nullptr) {
            return nullptr;
        }

        if (my_map.find(node->label) != my_map.end()) {
            return my_map.at(node->label);
        }

        UndirectedGraphNode *start_node = new UndirectedGraphNode(node->label);
        my_map.insert({start_node->label, start_node});
        for (UndirectedGraphNode *neighbor: node->neighbors) {
            start_node->neighbors.push_back(dfs(neighbor, my_map));
        }

        return start_node;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> my_map;
        return dfs(node, my_map);
    }

    UndirectedGraphNode *bfs(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;

        queue<UndirectedGraphNode *> my_queue;
        my_queue.push(node);
        map<int, UndirectedGraphNode *> my_map;
        UndirectedGraphNode *copy_head = new UndirectedGraphNode(node->label);
        my_map.insert({node->label, copy_head});
        while (!my_queue.empty()) {
            UndirectedGraphNode *front_node = my_queue.front();
            my_queue.pop();
            for (UndirectedGraphNode *neighbor: front_node->neighbors) {
                if (neighbor != nullptr) {
                    if (my_map.find(neighbor->label) == my_map.end()) {
                        my_map.insert({neighbor->label, new UndirectedGraphNode(neighbor->label)});
                        my_queue.push(neighbor);
                    }
                    front_node->neighbors.push_back(my_map[neighbor->label]);
                }

            }
        }
        return my_map.at(node->label);

    }

};


int main() {

}