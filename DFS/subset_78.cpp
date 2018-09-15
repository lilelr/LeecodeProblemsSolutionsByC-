
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
//
// Created by YuXiao on 9/15/18.
////
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note:
//        Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//        If nums = [1,2,3], a solution is:
//
//[
//[3],
//[1],
//[2],
//[1,2,3],
//[1,3],
//[2,3],
//[1,2],
//[]
//]
//
//这道题可以使用两种方法求解，一是使用位操作，另外是使用深度优先搜索和回溯，但是我只想出了位操作，深度优先的方法是看了Discuss后想出来的。
////解法一：位操作
//        对于数组[1,2,3]，可以用一个下标0和1表示是否选择该数字，0表示未选择，1表示选中，那么每一组3个0和1的组合表示一种选择，3位共有8种选择，分别是：
//000 对应[]
//001 对应[3]
//010 对应[2]
//011 对应[2,3]
//100 …
//101
//110
//111
//那么上面为1的位表示数组中该位被选中。
//那么只需要遍历0到1<< length中的数，判断每一个数中有那几位为1，为1的那几位即会构成一个子集中的一个元素。
//
//runtime:8ms


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        for(int i=0;i<1<<length;i++)
        {
            vector<int> tmp;
            //计算i中有那几位为1
            for(int j=0;j<length;j++)
            {
                //判断i中第j位是否为1
                if(i&1<<j)
                {
                    tmp.push_back(nums[j]);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }


};


//解法二：回溯法
//        还可以使用深度优先搜索来遍历数组，采用回溯法来剔除元素。使用一个变量来记录路径，每遍历到一个元素即表示找到一条路径，将其加入子集中。
//对于数组[1,2,3]
//从1开始递归查询2,3，对于2，继续向下搜索，搜索完后将2删除。
//runtime:8ms
//class Solution {
//public:
//    //使用深度优先的回溯法
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> result;
//        vector<int> path;
//        sort(nums.begin(),nums.end());
//        result.push_back(path);
//        dfs(nums,0,path,result);
//        return result;
//    }
//    void dfs(vector<int>& nums,int pos,vector<int> & path,vector<vector<int>> & result)
//    {
//        if(pos==nums.size())
//            return;
//
//        for(int i=pos;i<nums.size();i++)
//        {
//            path.push_back(nums[i]);
//            result.push_back(path);
//            dfs(nums,i+1,path,result);
//            path.pop_back();
//        }
//    }
//
//};