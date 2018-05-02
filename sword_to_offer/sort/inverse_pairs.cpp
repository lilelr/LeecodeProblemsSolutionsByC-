//
// Created by YuXiao on 5/2/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
const int MOD = 1000000007;

class Solution {
public:
    // 归并排序
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

    int inverse_pairs_core2(vector<int>& data, vector<int>& cache, int start, int end) {
        int ans = 0;

        if (start == end) {
            cache[start] = data[start];
            return 0;
        }
        for(int i=start;i<=end;i++){
            cache[i]= data[i];
        }
        int mid = (end + start) / 2;
        int left = inverse_pairs_core(data, cache, start, mid) % MOD;
        int right = inverse_pairs_core(data, cache, mid + 1, end) % MOD;

        int i = mid;
        int j = end;
        int cache_index = end;
        int count = 0;
        while (i >= start && j >= mid + 1) {
            if (cache[i] > cache[j]) {
                data[cache_index--] = cache[i--];
                count += (j - mid)%MOD;
                count %= MOD;
            } else {
                data[cache_index--] = cache[j--];
            }

        }
        for (; i >= start; i--) {
            data[cache_index--] = cache[i];
        }
        for (; j >= mid + 1; j--) {
            data[cache_index--] = cache[j];
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
};

int main() {
    Solution s;
  vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
//    vector<int> data = {1,2,3,0};

//    vector<int> data = {6,7,1,0};
    int ans = s.InversePairs(data);
    cout << ans << endl;
    return 0;
}