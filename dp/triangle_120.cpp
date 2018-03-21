//
// Created by YuXiao on 3/21/18.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        size_t num_length = triangle.size();
        int num[num_length] = {0};
        for (int i = 0; i < num_length; i++) {
            num[i] = triangle.at(num_length - 1).at(i);
        }

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                num[j] = triangle.at(i).at(j) + min(num[j], num[j + 1]);
            }
        }

        return num[0];
    }
};

int main() {
    cout << "ee" << endl;
}