/// Copyright 2016 yuXiao
// dynamic programming

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


struct compare{
 bool operator()(int& l, int& r){
     return l>r;
 }
};

//first solution: using priority_queue as a min_heap
//in C++, priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion
//time complexity: O(n*logk)
//space complexity: O(k)
 //220 ms
int findKthLargest(vector<int>& nums, int k){
    priority_queue<int ,vector<int>, compare> Q;
    for(auto num : nums){
        Q.push(num);
        cout<<Q.top()<<endl;
        if(Q.size() > k){
            Q.pop();
        }
    }
    return Q.top();
}


int main() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(1);
    int res = findKthLargest(arr,5);
    cout<<res<<endl;
    return 0;
}
