//
// Created by YuXiao on 4/7/16.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__GAMEOFLIFE289_H
#define LEECODEPROBLEMSSOLUTIONSBYC__GAMEOFLIFE289_H

#include <iostream>
#include <vector>
#include <altivec.h>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n < 0) return;
        int m = board[0].size();
        if (m < 0) return;
        /*
        11:1->1
        18:1->0
        81:0->1
        88:0->0
        */
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int iu = max(0, i - 1), iv = min(i + 1, n - 1);
                int ju = max(0, j - 1), jv = min(j + 1, m - 1);
                int c = 0 - board[i][j];
                for (int a = iu; a <= iv; ++a)
                    for (int b = ju; b <= jv; ++b){
                        int t = board[a][b];
                        if (t == 1 || t == 18 || t == 11)
                            ++c;
                    }
                if (board[i][j] == 0){
                    board[i][j] = (c == 3) ? 81 : 88;
                } else {
                    board[i][j] = (c == 2 || c == 3) ? 11 : 18;
                }
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                board[i][j] = (board[i][j] % 10 == 8) ? 0 : 1;
            }
        }
    }
};
#endif //LEECODEPROBLEMSSOLUTIONSBYC__GAMEOFLIFE289_H
