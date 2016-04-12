/// Copyright 2016 yuXiao

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

bool hasCycle(ListNode *head,ListNode*& cycleTag) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode *pre = head->next;
    ListNode *p = head->next->next;
    while (p != nullptr && p->next != nullptr && p->next->next != nullptr && p != pre) {
        p = p->next->next;
        pre = pre->next;
    }

    if (p == pre) {
        cycleTag = p;
        return true;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    ListNode* cycleTag;
    ListNode* tmpcycleTag;
    bool isCycle = hasCycle(head,cycleTag);
    if(isCycle){
       ListNode* cycleStart = head;
        while (true){
            ListNode* newhead = cycleStart->next;
            cycleStart->next= nullptr;
            if(hasCycle(cycleTag,tmpcycleTag)){
                cycleStart->next=newhead;
                cycleStart = newhead;
            } else{
                cycleStart->next=newhead;
                return cycleStart;
            }
        }

    } else{
        return nullptr;
    }
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *sec = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *forth = new ListNode(4);
    head->next = sec;
    sec->next = third;
    third->next = forth;
    forth->next = head;
    ListNode* ans;
    ans = detectCycle(head);
    cout << ans->val << endl;
    return 0;
}
