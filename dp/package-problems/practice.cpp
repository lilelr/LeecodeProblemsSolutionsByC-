//
// Created by YuXiao on 7/29/18.
//



#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;



vector<int> find_order(int numCourses, vector<pair<int, int>> &prerequisites) {
    if (numCourses == 0) return vector<int>();
    if (numCourses == 1) return vector<int>(1, 0);

    vector<int> ans(numCourses);
    vector<vector<int>> graph(numCourses);
    vector<int> in_degree(numCourses);

    for(int i=0;i<numCourses;i++){
        graph[i] = vector<int>();
        in_degree[i] =0;
    }

    for(pair<int,int>& cur:prerequisites){
        graph[cur.second].push_back(cur.first);
        in_degree[cur.first]++;
    }

    stack<int> my_stack;
    for(int i=0;i<numCourses;i++){
        if(in_degree[i]==0){
            my_stack.push(i);
        }
    }

    int count=0;
    while (!my_stack.empty()){
        int pop_val = my_stack.top();
        my_stack.pop();
        ans[count] = pop_val;
        count++;

        int temp_len = graph[pop_val].size();
        for(int i=0;i<temp_len;i++){
            int cur_pos= graph[pop_val][i];
            in_degree[cur_pos]--;
            if(in_degree[cur_pos]==0){
                my_stack.push(cur_pos);
            }

        }
    }




}
int main() {

}