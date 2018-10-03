#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>

using namespace std;
//https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
//https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
int n;
 vector<int> nums;

class Solution {
private:

    struct Position {
        int x, y;

        Position(int a, int b) : x(a), y(b) {

        }
    };

    struct compare {
        bool operator()(const Position &l, const Position &r) {
            return nums[l.x] * nums[n - 1 - r.y] > nums[r.x] * nums[n - 1 - l.y];
        }
    };

    priority_queue<Position, vector<Position>, compare> pq;

public:
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        n = A.size();
        nums = A;

        int len = n;
        for (int i = 0; i < len; i++) {
            pq.push(Position(i, 0));
        }

        while (K--) {
            Position p = pq.top();
            pq.pop();
            if (++p.y < n) {
                pq.push(p);
            }
        }
        vector<int> res;
        Position t = pq.top();
        int ans_a = A[t.x];
        int ans_b = A[n - 1 - t.y];
        res.push_back(ans_a);
        res.push_back(ans_b);
        return res;

    }
};

int main(){
     Solution s;
    vector<int> nums = {1,2,3,5};
    int k = 3;
    vector<int> res = s.kthSmallestPrimeFraction(nums, k);
    for(auto& item:res){
        cout<<item<<endl;
    }
}