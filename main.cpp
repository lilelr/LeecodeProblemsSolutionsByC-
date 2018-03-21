/// Copyright 2016 yuXiao
// dynamic programming

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 440ms
int numSquares(int n) {
   if(n <=0){
       return 0;
   }

    vector<int> perfectSquares;
    vector<int> cntPerfectSquares(n);

    for(int i=1;i*i<=n;i++){
        perfectSquares.push_back(i*i);
        cntPerfectSquares[i*i-1] = 1;
    }

    if(perfectSquares.back() == n){
        return 1;
    }

    queue<int> searchQ;
    for(auto& item: perfectSquares){
        searchQ.push(item);
    }

    int currCntPerfectSquares = 1;
    while (!searchQ.empty()){
        currCntPerfectSquares++;

        int searchQSize = searchQ.size();
        for(int i=0;i< searchQSize;i++){
            int frontItem = searchQ.front();
            for(auto& j:perfectSquares){
                if(frontItem+j == n){
                    return currCntPerfectSquares;
                }
                else if ((frontItem+j <n) && (cntPerfectSquares[frontItem+j-1] == 0)){
                    cntPerfectSquares[frontItem+j-1] = currCntPerfectSquares;
                    searchQ.push(frontItem+j);
                }
                else if(frontItem+j > n){
                    break;
                }
            }
            searchQ.pop();
        }
        return 0;
    }
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
