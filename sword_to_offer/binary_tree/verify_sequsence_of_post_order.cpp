//
// Created by YuXiao on 4/15/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool help_verifySequenceOfBST(vector<int> sequence, int start, int end) {
        if (start < end) {
            int root = sequence[end];
            int i = start;
            for (; i < end; i++) {
                if (sequence[i] > root) {
                    break;
                }
            }

            int j = i;
            for (; j < end; j++) {
                if (sequence[j] < root) {
                    return false;
                }
            }

            bool left = true;
            if (i > start) {
                left = help_verifySequenceOfBST(sequence, start, i - 1);
            }

            bool right = true;
            if (i < end) {
                right = help_verifySequenceOfBST(sequence, i, end - 1);
            }

            return (left && right);

        } else {
            return true;
        }

    }

    bool VerifySquenceOfBST(vector<int> sequence){
        int len = sequence.size();
        if (len <= 0) {
            return false;
        }
        bool res = help_verifySequenceOfBST(sequence, 0, len - 1);
        return res;
    }
};


int main() {
//     vector<int> sequence = {5,7,6,9,11,10,8};
    vector<int> sequence = {7,4,6,5};

    Solution s;
    bool res = s.VerifySquenceOfBST(sequence);
    cout<<res<<endl;
}