//
// Created by YuXiao on 3/28/18.
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

};

void zero_one_package() {
    int total_weight = 10;
    while (cin >> total_weight) {
        int w[5] = {5, 4, 3, 2, 1};
        int v[5] = {1, 2, 3, 4, 5};

        int dp[total_weight + 1];
        for (int &item:dp) {
            item = 0;
        }
        int n = 5;
        for (int i = 0; i < n; i++) {  // 挑选第i种物品
            // 逆序遍历， 满足每种物品只有一个的条件
            for (int j = total_weight; j >= w[i]; j--) { // 不超过包的总体积或总体重限制下，计算现在包的总价值
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        int result = dp[total_weight];
        cout << result << endl;
    }

}

void complete_package() {
    int total_weight = 10;
    while (cin >> total_weight) {
        int w[5] = {5, 4, 3, 2, 1};
        int v[5] = {1, 2, 3, 4, 5};

        int dp[total_weight + 1];
        for (int &item:dp) {
            item = 0;
        }
        int n = 5;
        for (int i = 0; i < n; i++) { // 挑选第i种物品
            // 顺序遍历， 满足每种物品有无限个的条件
            for (int j = w[i]; j <= total_weight; j++) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        int result = dp[total_weight];
        cout << result << endl;
    }

}

// 多重背包问题
void multiple_package() {
    int total_weight = 10;
    while (cin >> total_weight) {
        int w[5] = {5, 4, 3, 2, 1};
        int v[5] = {1, 2, 3, 4, 5};
        int numbers[5] = {1, 2, 1, 2, 1};
        int dp[total_weight + 1];
        for (int &item:dp) {
            item = 0;
        }
        int n = 5;
        for (int i = 0; i < n; i++) { // 挑选第i种物品
            // 逆序遍历，第i种物品有numbers[i]个，可以看作第i种物品有 numbers[i] 种，再次运用0-1背包问题思想
            for (int k = 0; k < numbers[i]; k++) {
                // 不超过包的总体积或总体重限制下，计算现在包的总价值
                for (int j = total_weight; j >= w[i]; j--) {
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }

        }
        int result = dp[total_weight];
        cout << result << endl;
    }

}
// https://www.cnblogs.com/tgycoder/p/5329424.html
// 题目描述：
//为了挽救灾区同胞的生命，心系灾区同胞的你准备自己采购一些粮食支援灾区，现在假设你一共有资金n元，而市场有m种大米，每种大米都是袋装产品，其价格不等，并且只能整袋购买。请问：你用有限的资金最多能采购多少公斤粮食呢？
//输入：
//输入数据首先包含一个正整数C，表示有C组测试用例，每组测试用例的第一行是两个整数n和m(1<=n<=100, 1<=m<=100),分别表示经费的金额和大米的种类，然后是m行数据，每行包含3个数p，h和c(1<=p<=20,1<=h<=200,1<=c<=20)，分别表示每袋的价格、每袋的重量以及对应种类大米的袋数。
//输出：
//对于每组测试数据，请输出能够购买大米的最多重量，你可以假设经费买不光所有的大米，并且经费你可以不用完。每个实例的输出占一行。
//样例输入：
//1
//8 2
//2 100 4
//4 100 2
//样例输出：
// 400

/* https://www.cnblogs.com/powerLEO101/p/7695179.html
转化为01背包问题
        另一种好想好写的基本方法是转化为01背包求解：把第i种物品换成n[i]件01背包中的物品，则得到了物品数为Σn[i]的01背包问题，直接求解，复杂度仍然是O(V*Σn[i])。
但是我们期望将它转化为01背包问题之后能够像完全背包一样降低复杂度。仍然考虑二进制的思想，我们考虑把第i种物品换成若干件物品，使得原问题中第i种物品可取的每种策略——取0..n[i]件——均能等价于取若干件代换以后的物品。另外，取超过n[i]件的策略必不能出现。
方法是：将第i种物品分成若干件物品，其中每件物品有一个系数，这件物品的费用和价值均是原来的费用和价值乘以这个系数。使这些系数分别为1,2,4,…,2^(k-1),n[i]-2^k+1，且k是满足n[i]-2^k+1>0的最大整数。例如，如果n[i]为13，就将这种物品分成系数分别为1,2,4,6的四件物品。
分成的这几件物品的系数和为n[i]，表明不可能取多于n[i]件的第i种物品。另外这种方法也能保证对于0..n[i]间的每一个整数，均可以用若干个系数的和表示，这个证明可以分0..2^k-1和2^k..n[i]两段来分别讨论得出，并不难，希望你自己思考尝试一下。
这样就将第i种物品分成了O(log n[i])种物品，将原问题转化为了复杂度为O(V*Σlog n[i])的01背包问题，是很大的改进。
 */
struct Rice {
    int price;
    int weight;
} rice[2001];

void multiple_packages_2() {
    int dp_rice[101];
    int n_case;
    cin >> n_case;
    while (n_case--) {
        int sum_money, spe_rice;
        cin >> sum_money >> spe_rice;
        int index = 0;
        int t_spec = spe_rice;
        int pr, wei, num;
        while (t_spec--) {
            cin >> pr >> wei >> num;
            int k = 1;
            while (num - k > 0) {
                num -= k;
                rice[++index].price = pr * k;
                rice[index].weight = wei * k;
                k *= 2;
            }
            rice[++index].price = pr * num;
            rice[index].weight = wei * num;
        }

        for (int j = 0; j <= sum_money; j++) {
            dp_rice[j] = 0;
        }

        for (int i = 1; i <= index; i++) {
            for (int j = sum_money; j >= rice[i].price; j--) {
                dp_rice[j] = max(dp_rice[j], dp_rice[j - rice[i].price] + rice[i].weight);
            }
        }
        int result = dp_rice[sum_money];
        cout << result << endl;
    }


}

// https://www.cnblogs.com/Renyi-Fan/archive/2017/08/25/7426217.html
void methods_complete_package() {
    int n, V;
    cin >> n >> V;
    vector<int> coins(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(V+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= coins[i]; j--) {
            for (int k = 1; k <= j / coins[i]; k++) {
                dp[j] = dp[j] + dp[j - k * coins[i]];
            }
        }
    }
    cout<<dp[V]<<endl;
}

// 而对于背包问题，每一个状态无非就是两种情况：取、不取。所以在计算方案的时候，我就把取或者不取加上来就好了。完全背包问题，有多少种取法
//【例9-17】、货币系统
//【问题描述】
//　　给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。样例：设n=3，m=10，要求输入和输出的格式如下：
//【样例输入】money.in
//3 10 //3种面值组成面值为10的方案
//1 //面值1
//2 //面值2
//5 //面值5
//【样例输出】money.out
//
//3 10
//1
//2
//5
void methods_complete_package2() {
    int n, V;
    cin >> n >> V;
    vector<int> coins(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n+1);
    for(int i=0;i<n+1;i++){
        dp[i] = vector<int>(V+1,0);
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=V;j++){
            if(j<coins[i]){
                dp[i][j]= dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
            }
        }
    }
    cout<<dp[n][V]<<endl;

    cout<<dp[1][V]<<" "<<dp[2][V]<<" "<<endl;
    cout<<dp[2][2]<<endl;
    cout<<dp[2][3]<<endl;
}


int main() {
//    complete_package();
//    multiple_package();
//    multiple_packages_2();

    methods_complete_package2();
}