//
// Created by YuXiao on 4/15/18.
//

#include <vector>
#include <iostream>

using namespace std;
const int MOD = 1000000007;

/**
 *
 * @param a   原始数组
 * @param low 要排序的起点下标
 * @param mid
 * @param high
 * @param b 复制的数组
 */
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
// 归并排序2，不用每次都复制数组
int inverse_pairs_core(vector<int>& data, vector<int>& cache, int start, int end) {
    int ans = 0;

    if (start == end) {
        cache[start] = data[start];
        return 0;
    }
    int mid = (end + start) / 2;
    int left = inverse_pairs_core(cache, data, start, mid) % MOD;
    int right = inverse_pairs_core(cache, data, mid + 1, end) % MOD;

    int i = mid;
    int j = end;
    int cache_index = end;
    int count = 0;
    while (i >= start && j >= mid + 1) {
        if (data[i] > data[j]) {
            cache[cache_index--] = data[i--];
            count += (j - mid)%MOD;
            count %= MOD;
        } else {
            cache[cache_index--] = data[j--];
        }

    }
    for (; i >= start; i--) {
        cache[cache_index--] = data[i];
    }
    for (; j >= mid + 1; j--) {
        cache[cache_index--] = data[j];
    }

    ans = (left + right + count) % MOD;

    return ans;

}


int InversePairs(vector<int> data) {
    int len = data.size();
    if (len <= 0) return 0;

    vector<int> cache(data);
//        for (int i = 0; i < len; i++) {
//            cout << cache[i] << endl;
//        }
//        int res = inverse_pairs_core(data, cache, 0, len - 1);
    int res = inverse_pairs_core2(data, cache, 0, len - 1);
    return res;

}

int main() {
    vector<int> nums = {3, 4, 1, 2};
    vector<int> cache(nums.size());
    mergesort(nums, 0, nums.size() - 1, cache);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}