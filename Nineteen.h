//
// Created by YuXiao on 3/26/16.
//

#ifndef LEECODPROJECT_NINETEEN_H
#define LEECODPROJECT_NINETEEN_H

#include <stddef.h>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || head->next==NULL) {
            return NULL;
        }
        ListNode* r=head->next;
        ListNode* pre=head;
        ListNode* p=head->next;
        while (n--) {
            r=r->next;
        }
        while (r!=NULL) {
            r=r->next;
            p=p->next;
            pre=pre->next;
        }
        pre->next=p->next;

        delete p;
        return head;

    }
};

#endif //LEECODPROJECT_NINETEEN_H
