//
// Created by YuXiao on 5/11/18.
//

作者：没有好offer啊
        链接：https://www.nowcoder.com/discuss/80754?type=0&order=0&pos=18&page=1
        来源：牛客网

#include <cstdio>
#include <algorithm>
#include <climits>
// 作者：没有好offer啊
//        链接：https://www.nowcoder.com/discuss/80754?type=0&order=0&pos=18&page=1
//        来源：牛客网
//https://www.nowcoder.com/discuss/80754?type=0&order=0&pos=18&page=1
//        算法岗两道编程题，一道是八卦阵，矩阵中有八个不相连的区域，每个区域由相邻的大于零的数字组成，区域与区域之间由零隔开，求这些区域的和的最大值和最小值是多少。
//
//思路是遍历矩阵，寻找不为0的值，将其置为0，然后从这个位置出发dfs搜索相邻的位置。
using namespace std;
 
int **mat;
int m, n;
 
int single(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0)
            return 0;
        int t = mat[i][j];
        mat[i][j] = 0;
        for (int a = -1; a <= 1; a++)
            for (int b = -1; b <= 1; b++)
                t += single(i + a, j + b);
        return t;
}
 
int main() {
        scanf("%d", &m);
        scanf("%d", &n);
        mat = new int*[m];
        for (int i = 0; i < m; i++)
            mat[i] = new int[n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        int zmax = INT_MIN, zmin = INT_MAX;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                    if (mat[i][j] != 0) {
                            int t = single(i, ***ax = max(zmax, t);
                            zmin = min(zmin, t);
                        }
                }
        printf("%d\n%d\n", zmax, zmin);
     
        return 0;
}

一道是寻找有向图中这样的一个结点，从这个结点出发的路径数量是最多的。也是dfs解决
        作者：没有好offer啊
        链接：https://www.nowcoder.com/discuss/80754?type=0&order=0&pos=18&page=1
        来源：牛客网

#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
 
using namespace std;
 
int N;
int M;
int vis[10000];
vector<int> m[10000];
 
int traverse(int n) {
        if (vis[n] != -1)
            return vis[n];
        int t = 0;
        for (int i = 0; i < m[n].size(); i++) {
                t = t + traverse(m[n][i]) + 1;
            }
        vis[n] = t;
        return t;
}
 
int main() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            vis[i] = -1;
        int t;
        scanf("%d%d", &M, &t);
        for (int i = 0; i < M; i++) {
                int a, b;
                scanf("%d%d", &a, &b);
                m[a].push_back(b);
            }
        int zmax = INT_MIN;
        int zi = 0;
        for (int i = 0; i < N; i++) {
                t = traverse(i);
                if (t > zmax) {
                        zi = i;
                        zmax = t;
                    }
            }
        printf("%d\n", zmax);
        return 0;
     
}