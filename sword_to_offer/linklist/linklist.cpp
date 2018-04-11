//
// Created by YuXiao on 4/11/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:

    void add_list_from_tail_to_head(ListNode* head, vector<int>& res){
        if(head == nullptr) return;

        add_list_from_tail_to_head(head->next,res);
        res.push_back(head->val);
    }

    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        add_list_from_tail_to_head(head, res);
        return res;
    }
};


int main() {

}