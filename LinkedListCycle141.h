//
// Created by YuXiao on 16/4/12.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__LINKEDLISTCYCLE141_H
#define LEECODEPROBLEMSSOLUTIONSBYC__LINKEDLISTCYCLE141_H
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head== nullptr || head->next== nullptr ) return false;

    ListNode* pre= head->next;
    ListNode* p = head->next->next;
    while (p!= nullptr && p->next!= nullptr && p->next->next!= nullptr && p!=pre){
        p=p->next->next;
        pre=pre->next;
    }

    if(p==pre) return true;
    return false;


}
int main() {
    ListNode* head = new ListNode(1);
    ListNode* sec = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    head->next=sec;
    sec->next = third;
    third->next = forth;
    forth->next = head;
    cout<<hasCycle(head)<<endl;
    return 0;
}
#endif //LEECODEPROBLEMSSOLUTIONSBYC__LINKEDLISTCYCLE141_H
