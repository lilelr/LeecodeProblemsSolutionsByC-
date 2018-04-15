//
// Created by YuXiao on 4/15/18.
//

#include <vector>
#include <iostream>

using namespace std;


void merge(vector<int> &a, int low, int mid, int high, vector<int> &b) {
    for (int i = low; i <= high; i++) {
        b[i] = a[i];
    }

    int i, j, k;
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
        if (b[i] < b[j]) {
            a[k] = b[i++];
        } else {
            a[k] = b[j++];
        }
    }
    for (; i <= mid; i++) {
        a[k++] = b[i];
    }
    for (; j <= high; j++) {
        a[k++] = b[j];
    }

}

void mergesort(vector<int> &a, int low, int high, vector<int> &b) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid, b);
        mergesort(a, mid + 1, high, b);
        merge(a, low, mid, high, b);
    }
}

int main() {
    vector<int> nums = {3, 4, 1, 2};
    vector<int> cache(nums.size());
    mergesort(nums, 0, nums.size() - 1, cache);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}