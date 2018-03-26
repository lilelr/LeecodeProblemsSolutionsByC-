//
// Created by YuXiao on 3/25/
//https://leetcode.com/problems/add-two-numbers/description/
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }

        if (l2 == nullptr) return l1;
        if (l1 == nullptr) return l2;

        ListNode *first_node = new ListNode(0);
        int first_val = l1->val + l2->val;
        int pre_val = first_val / 10;
        int cur_val = first_val % 10;
        first_node->val = cur_val;
        ListNode *p = first_node;
        l1 = l1->next;
        l2 = l2->next;
        int val;
        while (l1 != nullptr && l2 != nullptr) {
            val = pre_val + l1->val + l2->val;
            pre_val = val / 10;
            cur_val = val % 10;
            ListNode *insert_node = new ListNode(cur_val);
            p->next = insert_node;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != nullptr) {
            while (l1 != nullptr) {
                val = pre_val + l1->val;
                pre_val = val / 10;
                cur_val = val % 10;
                ListNode *insert_node = new ListNode(cur_val);
                p->next = insert_node;
                p = p->next;
                l1 = l1->next;
            }
        }

        if (l2 != nullptr) {
            while (l2 != nullptr) {
                val = pre_val + l2->val;
                pre_val = val / 10;
                cur_val = val % 10;
                ListNode *insert_node = new ListNode(cur_val);
                p->next = insert_node;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (pre_val != 0) {
            ListNode *insert_node = new ListNode(pre_val);
            insert_node->next = nullptr;
            p->next = insert_node;
        } else {
            p->next = nullptr;
        }

        return first_node;
    }

};


int main() {

}