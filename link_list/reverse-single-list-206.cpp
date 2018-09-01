#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
// https://leetcode.com/problems/reverse-linked-list/description/
class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) { }
    };

    ListNode* reverseList(ListNode* head) {
        // 判断只有一个节点或无节点的特殊情况
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre, *p;
        pre = head;
        p = pre->next;
        pre->next = nullptr;
        // 以p 为核心遍历
        while (p!= nullptr){
            ListNode* s = p->next;
            p->next = pre;
            pre = p;
            p = s;
        }
        return pre;
    }

};
