//
// Created by YuXiao on 3/26/18.
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
//

#include <vector>
#include <iostream>

using namespace std;

void rebuild_heap(vector<int> &min_heap, int i) {
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    if (left_child >= min_heap.size()) return;
    if (right_child >= min_heap.size()) {
        if (min_heap[i] > min_heap[left_child]) {
            swap(min_heap[i], min_heap[left_child]);
        }
        return;
    }
    int min_index = min_heap[left_child] < min_heap[right_child] ? left_child : right_child;

    if (min_heap[i] > min_heap[min_index]) {
        swap(min_heap[i], min_heap[min_index]);
        rebuild_heap(min_heap, min_index);
    }
}

void initialize_min_heap(vector<int> &min_heap) {
    int len = min_heap.size();
    if (len <= 1) return;
    int pos = (len - 2) / 2;
    while (pos >= 0) {
        rebuild_heap(min_heap, pos);
        pos--;
    }

}

int find_kth_largest(vector<int> &nums, int k) {
    if (nums.size() == 0) return -1;
    vector<int> min_heap(k, 0);
    for (int i = 0; i < k; i++) {
        min_heap[i] = nums[i];
    }
    initialize_min_heap(min_heap);
    for (int j = k; j < nums.size(); j++) {
        if (min_heap[0] < nums[j]) {
            min_heap[0] = nums[j];
            rebuild_heap(min_heap, 0);
        }
    }
    return min_heap[0];
}

int main() {
    vector<int> test_vec = {5, 4, 3, 2, 1};
    vector<int> test_vec1 = {4, 5, 6};
    vector<int> test_vec2 = {1, 1, 6, 2, 1};
    vector<int> test_vec3 = {6, 1, 0, 12, 34, 12};

    int res0_test_vec = find_kth_largest(test_vec, 2);
    cout << res0_test_vec << endl;

    int res1_test_vec = find_kth_largest(test_vec1, 3);
    cout << res1_test_vec << endl;

    int res2_test_vec = find_kth_largest(test_vec2, 2);
    cout << res2_test_vec << endl;

    int res3_test_vec = find_kth_largest(test_vec3, 5);
    cout << res3_test_vec << endl;
}
