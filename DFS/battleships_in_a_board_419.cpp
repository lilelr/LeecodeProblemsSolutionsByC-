https://leetcode.com/problems/battleships-in-a-board/description/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 0x3f3f3f3f;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if(i>=1 && board[i-1][j] == 'X'){
                        continue;
                    }
                    if(j>=1 && board[i][j-1] == 'X'){
                        continue;
                    }

                    cnt++;
                }
            }
        }

        return cnt;
    }


};


int main() {

}