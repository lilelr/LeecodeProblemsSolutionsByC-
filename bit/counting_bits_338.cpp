#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
// https://leetcode.com/problems/counting-bits/discuss/170166/Python-DP-Solution-Simple-and-easy-to-understand.-()
//Beats: 63.94%
//Time Complexity: O(n)
//Remark: 考察二进制的时候，多向左移右移的方向考虑。
//
//Explanation:
//
//        Step1: 判断
//        朝O(n)的时间复杂度方向考虑，肯定需要用到子问题的解，不然不太可能。
//
//Step2: 状态
//状态自然是数i的二进制中包含1的个数count[i]。
//难度是如何找寻它与子问题的关系。
//
//Step3: 状态方程
//
//0: 0000 0000   0
//1: 0000 0001   1
//2: 0000 0010   1
//3: 0000 0011   2
//4: 0000 0100   1
//5: 0000 0101   2
//6: 0000 0110   2
//7: 0000 0111   3
//8: 0000 1000   1
//观察0-8的二进制，会比较自然的朝左移右移的角度去想。一个数的二进制左移一位相当于翻倍，反之减小一般。奇数比较特别的地方在于左移的时候末尾补0，右移的时候原来末尾的1会丢失。基于这个想法，对于数i，在不考虑原本末位的情况下，我们不难想到右移后i与i>>1的二进制中含有相同个数的1。再加上末位可能有的1，就可以得到i中含有1的个数了。
//得到状态方程：count[i] = count[i>>1] + (i & 1)
//
//Step4: Tabulation or Memorizatio
//        两种方法都可以。

using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
            vector<int> res;
            res.push_back(0);
            for(int i=1;i<=num;i++){
                int cur = res[i>>1] + (i&1);
                res.push_back(cur);
            }
            return res;

    }
};