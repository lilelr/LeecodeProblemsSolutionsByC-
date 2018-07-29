//
// Created by YuXiao on 7/29/18.
//



#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
    if(prices.size() <2) {
        return 0;
    }

    int trans = 2;
    int len = prices.size();

    vector<vector<int>> dp(trans, vector<int>(len, 0));

    for (int i = 0; i < trans; i++) {
        int min_price = prices[0];
        if (i == 0) {

            for (int j = 1; j < len; j++) {
                min_price = min(min_price, prices[j]);
                dp[0][j] = max(dp[0][j - 1], prices[j] - min_price);
            }

        } else {
            dp[i][0] = 0;
            for (int j = 1; j < len; j++) {
                min_price = min(min_price, prices[j - 1] - dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j - 1], prices[j] - min_price);
            }
        }
    }

    int result = dp[trans - 1][len - 1];
    return result;
}

int main() {

}