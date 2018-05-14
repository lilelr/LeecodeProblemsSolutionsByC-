//
// Created by YuXiao on 5/14/18.
//https://leetcode.com/problems/create-maximum-number/description/
// https://leetcode.com/problems/create-maximum-number/discuss/77300/C++-DP+greedy-Solution-should-be-easy-to-understand
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// Here is the idea:

//Let's consider a similar but simple version of this problem: if there is only one array arr of which length is m, how to find the k digits of it to create maximum number preserving the order?
//So here comes to my DP solution: DP[ i ][ j ] means that the maximum number that has i digits we can get when the jth digits is the last one of this number. Thus the formula is as follows:
//
//dp[ i ] [ j ] = max(dp[ i ][ j ], max(dp[ i - 1 ][ 0 ... j - 1 ]))
//Ok. We apply this formula to the two given arrays and then get two DP arrays DP1 and DP2 where DP[ i ] means the largest number with i digits.
//
//Back to our problem: Choose k digits of these two arrays/strings to create the maximum number. Now here is the greedy solution:
//
//For every pair of i and j where i + j == k and i is the number of digits used from array1 and j is the number of digits used from array2, we have to combine to create a new number so that it is the largest of all combinations. Remember a similar greedy problem? The trick here is that we use two pointers for each array and in each iteration, pick up pointers pointing to the larger digit or the larger substring. Then the number created is the largest from the given two arrays/strings.
//
//Still confused? Plsz read the code below:

//Question
//Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
//Example 1:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//return [9, 8, 6, 5, 3]
//
//Example 2:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//return [6, 7, 6, 0, 4]
//
//Example 3:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//return [9, 8, 9]
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        if(!nums1.size() && !nums2.size() || !k)
            return ans;
        ans.resize(k);
        int n = nums1.size(), m = nums2.size();
        vector<string> dp1(min(k, n)), dp2(min(k, m));
        vector<string> dpprev1(n), dpcur1(n), dpprev2(m), dpcur2(m);

        for(int i = 0; i < dp1.size(); ++ i){
            string tmpval(i + 1, 0);
            dp1[i] = tmpval;
            if(!i){
                for(int j = 0; j < n; ++ j){
                    dpprev1[j] = "";
                    dpprev1[j] += (char)(nums1[j] + '0');
                    dp1[i] = max(dp1[i], dpprev1[j]);
                    if(j)
                        dpprev1[j] = max(dpprev1[j], dpprev1[j - 1]);

                }
            }else{
                for(int j = i; j < n; ++ j){
                    dpcur1[j] = tmpval;

                    dpcur1[j] = max(dpcur1[j], dpprev1[j - 1] + (char)(nums1[j] + '0'));

                    dp1[i] = max(dp1[i], dpcur1[j]);
                    if(j >= i)
                        dpcur1[j] = max(dpcur1[j], dpcur1[j - 1]);
                }
                dpprev1 = dpcur1;
            }

        }



        for(int i = 0; i < dp2.size(); ++ i){
            string tmpval(i + 1, 0);
            dp2[i] = tmpval;
            if(!i){
                for(int j = 0; j < m; ++ j){
                    dpprev2[j] = "";
                    dpprev2[j] += (char)(nums2[j] + '0');
                    dp2[i] = max(dp2[i], dpprev2[j]);
                    if(j)
                        dpprev2[j] = max(dpprev2[j], dpprev2[j - 1]);
                }
            }else{
                for(int j = i; j < m; ++ j){
                    dpcur2[j] = tmpval;

                    dpcur2[j] = max(dpcur2[j], dpprev2[j - 1] + (char)(nums2[j] + '0'));

                    dp2[i] = max(dp2[i], dpcur2[j]);
                    if(j >= i)
                        dpcur2[j] = max(dpcur2[j], dpcur2[j - 1]);
                }
                dpprev2 = dpcur2;
            }

        }


        string tmpans(k, 0), v = "";

        if(!dp1.size()){
            getAns(v, dp2[k - 1], ans, tmpans);
        }else{
            for(int i = 0; i <= min(k, (int)dp1.size()); ++ i){
                if(i == 0){
                    if(dp2.size() >= k)
                        getAns(v, dp2[k - 1], ans, tmpans);
                }else if(i < k){
                    if(dp2.size() >= k - i)
                        getAns(dp1[i - 1], dp2[k - i - 1], ans, tmpans);
                }else{
                    if(dp1.size() >= k)
                        getAns(dp1[k - 1], v, ans, tmpans);
                }
            }

        }

        return ans;
    }

private:
    void getAns(string &s1, string &s2, vector<int> &ans, string &tmpans){
        string res;
        if(!s1.size())
            res = s2;
        else if(!s2.size())
            res = s1;
        else{
            int id1 = 0, id2 = 0;

            while(id1 < s1.size() && id2 < s2.size()){
                if(s1[id1] > s2[id2]){
                    res += s1[id1 ++];
                }else if(s1[id1] < s2[id2]){
                    res += s2[id2 ++];
                }else{
                    if(s1.substr(id1) >= s2.substr(id2))
                        res += s1[id1 ++];
                    else
                        res += s2[id2 ++];
                }
            }
            while(id1 < s1.size())
                res += s1[id1 ++];
            while(id2 < s2.size())
                res += s2[id2 ++];
        }

        if(res > tmpans){
            tmpans = res;
            for(int i = 0; i < res.size(); ++ i)
                ans[i] = (res[i] - '0');
        }
    }
};