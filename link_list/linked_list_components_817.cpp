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
// https://leetcode.com/problems/linked-list-components/description/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:


    int numComponents(ListNode *head, vector<int> &G) {
        auto g_set = unordered_set<int>{begin(G), end(G)};
        cout<<g_set.size()<<endl;
        int max_size = 0;
        bool group_start = false;

        while (head != nullptr) {
            if (g_set.find(head->val) != g_set.end()) {
                if (!group_start) {
                    max_size++;
                    group_start = true;
                }
            } else {
                group_start = false;
            }
            head = head->next;
        }
        return max_size;
    }
};

int main() {

    ListNode *head = new ListNode(0);
    ListNode *second = new ListNode(1);
    ListNode *third = new ListNode(2);
    ListNode *fourth = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = fourth;
    vector<int> g = {0, 1, 3};
    Solution s;
    int res = s.numComponents(head, g);
    cout << res << endl;

    vector<int> av={1,2,3,4};
    unordered_set<int> uorder_set{begin(av),end(av)};
    cout<<"------------"<<endl;
    for(auto it=uorder_set.begin();it!=uorder_set.end();it++){
        cout<<*it<<endl;
    }

}