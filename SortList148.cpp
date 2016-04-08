//
// Created by YuXiao on 4/8/16.
//

#include <tkDecls.h>
#include "SortList148.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

 // quickSort O(nlogn) in place
ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode lh(0), rh(0), mh(0);
    ListNode *lt = &lh, *mt = &mh, *rt = &rh;
    int val = head->val;
    while (head!=NULL){
        if(val==head->val){
            mt->next = head;
            mt = mt->next;
        } else if (val > head->val){
        // Comparison determines the sort as descending order or ascending order.
         //   Greater than generates the ascending order.
            lt->next = head;
            lt = lt->next;
        }else{
            rt->next = head;
            rt = rt->next;
        }
        head=head->next;
    }
    lt->next= NULL;
    rt->next = NULL;
    lh.next = sortList(lh.next);
    rh.next = sortList(rh.next);
    lt = &lh;
    while (lt->next!=NULL){
        lt = lt->next;
    }
    lt->next = mh.next;
    mt->next = rh.next;
    return lh.next;
}