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
// 随机数  reservoir-sampling 算法
//https://leetcode.com/problems/linked-list-random-node/discuss/85690/using-%22Reservoir-sampling%22-O(1)-space-O(n)-time-complexityc++

struct ListNode{
    int val;
    ListNode* next;
};
class Solution {

private:
    ListNode* head;
public:
   Solution(ListNode* head){
       this->head = head;
   }

    int getRandom(){
        int res = head->val;
        ListNode* node = head->next;
        int i=2;
        while (node){
            int j = rand()%i; // 产生 [0,i) 之间的随机数
            if(j==0){
                res = node->val;  // 根据Reservoir-sampling 算法，选择第i个元素
            }
            i++;
            node = node->next;
        }
        return res;
    }
};