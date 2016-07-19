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

    static vector<int> cntSqures({0});
    while (cntSqures.size() <= n) {
        int curSize = cntSqures.size();
        int newSqures = INT_MAX;
        for (int j = 1; j * j <= curSize; j++) {
            newSqures = min(newSqures, cntSqures[curSize - j * j] + 1);
        }
        cntSqures.push_back(newSqures);
    }
    return cntSqures[n];
}

int main() {
//    vector<int> arr;
//    arr.push_back(2);
//    arr.push_back(4);
//    arr.push_back(6);
//    arr.push_back(9);
//    arr.push_back(1);
//    int res = findKthLargest(arr,5);
    cout << numSquares(1024) << endl;
    cout << "e" << endl;
    return 0;
}
