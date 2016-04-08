//
// Created by YuXiao on 4/8/16.
//

#ifndef LEECODEPROBLEMSSOLUTIONSBYC__SORTLIST148_H
#define LEECODEPROBLEMSSOLUTIONSBYC__SORTLIST148_H


#include <stddef.h>

class SortList148 {
public:
 // Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode* sortList(ListNode* head);

};


#endif //LEECODEPROBLEMSSOLUTIONSBYC__SORTLIST148_H
