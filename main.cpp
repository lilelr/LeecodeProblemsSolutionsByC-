#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <list>
#include <unordered_set>
#include <set>

//https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100733/Java-Binary-Search-with-Detailed-Explanation
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        vector<unordered_map<int,int>> dp(n,unordered_map<int,int>());
        // dp[i][diff] 以当前A[i] 为数组末尾元素，差为diff 的数组个数
        unordered_set<int> mmset(A.begin(), A.end());
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];

                int add_on = 0;
                if(dp[j].count(diff) !=0){
                    add_on = dp[j][diff];
                }

                if(mmset.count(A[i]+diff)!=0){
                    add_on+=1;
                }
                dp[i][diff]+=add_on;
                res+=add_on;
            }
        }
    }

};

struct Mycomp { // 对于 set 而言，比较顺序按照正常顺序来
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
        if (l.first != r.first) {
            return l.first < r.first;
        } else {
            return l.second < r.second;
        }
    }
};

struct MyQueueComp {// 对于 priority_queue 而言，比较顺序就需要反着来
    bool operator()(const int &l, const int &r) {
        return l < r; // 实际是最大堆
    }
};
int main() {
    set<pair<int, int>, Mycomp> mset;
    mset.insert(make_pair(1, 2));
    mset.insert(make_pair(5, 56));
    mset.insert(make_pair(1, 3));
    set<pair<int, int>, Mycomp>::iterator it;
    for (it = mset.begin(); it != mset.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    priority_queue<int, vector<int>, MyQueueComp> priority_queue1;
    priority_queue1.push(1);
    priority_queue1.push(2);
    priority_queue1.push(3);

    while (!priority_queue1.empty()) {
        int t = priority_queue1.top();
        priority_queue1.pop();
        cout << t << endl;
    }
    return 0;
}