//
// Created by YuXiao on 3/26/18.
//

#include <vector>
#include <iostream>

using namespace std;

/**
 *
 * @param nums  待分区的数组
 * @param begin 起点
 * @param end  终点
 * @return 分区的数的下标
 */
int partition(vector<int> &nums, int begin, int end) {
    if (begin < end) {
        int pivot = nums[begin];// 哨兵
        int i = begin, j = end;
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];

            while (i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;

    }
}

void quick_sort(vector<int> &nums, int begin, int end) {
    if (begin < end) {
        int boundary = partition(nums, begin, end);
        quick_sort(nums, begin, boundary - 1);
        quick_sort(nums, boundary + 1, end);
    }


}


int main() {
    vector<int> test_vec = {5, 4, 3, 2, 1};
    vector<int> test_vec1 = {4, 5, 6};
    vector<int> test_vec2 = {1, 1, 6, 2, 1};
    vector<int> test_vec3 = {6, 1, 0, 12, 34, 12};
    quick_sort(test_vec, 0, test_vec.size() - 1);
    quick_sort(test_vec1, 0, test_vec1.size() - 1);
    quick_sort(test_vec2, 0, test_vec2.size() - 1);
    quick_sort(test_vec3, 0, test_vec3.size() - 1);
    for (auto item:test_vec) {
        cout << item << " ";
    }
    cout << "\n";
    for (auto item:test_vec1) {
        cout << item << " ";
    }
    cout << "\n";

    for (auto item:test_vec2) {
        cout << item << " ";
    }
    cout << "\n";

    for (auto item:test_vec3) {
        cout << item << " ";
    }
    cout<<"\n";
}
