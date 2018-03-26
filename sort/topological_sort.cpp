//
// Created by YuXiao on 3/26/18.
//https://leetcode.com/problems/course-schedule-ii/description/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> find_order(int numCourses, vector<pair<int, int>> &prerequisites) {
    if (numCourses == 0) return vector<int>();
    if (numCourses == 1) return vector<int>(1, 0);

    vector<int> ans(numCourses);
    vector<vector<int>> graph(numCourses);
    vector<int> in_degree(numCourses);

    for (int i = 0; i < numCourses; i++) {
        in_degree[i] = 0;
        graph[i] = vector<int>();
    }

    for (pair<int, int> item: prerequisites) {
        graph[item.second].push_back(item.first);
        in_degree[item.first]++;
    }

    stack<int> stack;
    for (int i = 0; i < numCourses; i++) {
        if (in_degree[i] == 0) {
            stack.push(i);
        }
    }

    int count = 0;
    while (!stack.empty()) {
        int pop_val = stack.top();
        stack.pop();
        ans[count] = pop_val;
        count++;

        int tmp_size = graph[pop_val].size();
        for (int i = 0; i < tmp_size; i++) {
            int point_val = graph[pop_val].at(i);
            in_degree[point_val]--;
            if (in_degree[point_val] == 0) {
                stack.push(point_val);
            }
        }
    }

    if (count < numCourses) return vector<int>();
    return ans;
}


int main() {
    vector<int> test_vec = {5, 4, 3, 2, 1};
    vector<int> test_vec1 = {4, 5, 6};
    vector<int> test_vec2 = {1, 1, 6, 2, 1};
    vector<int> test_vec3 = {6, 1, 0, 12, 34, 12};

}
