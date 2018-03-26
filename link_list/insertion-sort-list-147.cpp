//
// Created by YuXiao on 3/25/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) { }
    };

    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* begin_node = new ListNode(0);
        begin_node->next = head;
        ListNode* p = head->next;
        head->next = nullptr;
        ListNode* pre;
        while (p!= nullptr){
            ListNode* r = p;
             p = p->next;
            r->next = nullptr;
            pre= begin_node;
            while (pre->next != nullptr && pre->next->val <= r->val){
                pre = pre->next;
            }
            r->next = pre->next;
            pre->next = r;
        }
        return  begin_node->next;
    }
};


int main() {

}