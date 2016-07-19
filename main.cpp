/// Copyright 2016 yuXiao
// dynamic programming

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

 // 440ms
int numSquares(int n) {
    if (n <= 0) {
        return 0;
    }

    vector<int> cntSqures(n + 1, INT_MAX);
    cntSqures[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            cntSqures[i] = min(cntSqures[i], cntSqures[i - j * j] + 1);
        }
    }

    return cntSqures.back();
}

int main() {
//    vector<int> arr;
//    arr.push_back(2);
//    arr.push_back(4);
//    arr.push_back(6);
//    arr.push_back(9);
//    arr.push_back(1);
//    int res = findKthLargest(arr,5);
    cout << numSquares(12) << endl;
    cout << "e" << endl;
    return 0;
}
