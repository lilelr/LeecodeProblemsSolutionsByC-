// 有一个单向链表，可能有环也可能无环，请把这个链表复制一份

// 阿里巴巴面试题
#include<iostream>

using namespace std;

struct Node {
    int val_;
    struct Node *next;
    bool is_copy;

    Node(int val) : next(NULL), val_(val), is_copy(false) {
    }
};

Node *copy_single_list(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return new Node(head->val_);
    Node *next_p;
    Node *cur;
    cur = head;
    next_p = cur->next;
    int len = 0;
    while (next_p != NULL && !(next_p->val_ == cur->val_ && next_p->is_copy)) {
        Node *copy_node = new Node(cur->val_);
        copy_node->is_copy = true;
        cur->next = copy_node;
        copy_node->next = next_p;
        cur = next_p;
        next_p = cur->next;
        len++;
    }

    if (next_p == NULL) {
        Node *copy_node = new Node(cur->val_);
        copy_node->is_copy = true;
        cur->next = copy_node;
    }

    cur = head;
    Node *copy_head = head->next;
    Node *ans = copy_head;
    Node *copy_next;

    while (len > 0) {
        next_p = cur->next->next;
        cur->next = next_p;
        copy_next = copy_head->next->next;
        copy_head->next = copy_next;
        cur = next_p;
        copy_head = copy_next;
        len--;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    Node *s1 = new Node(1);
    Node *s2 = new Node(2);
    Node *s3 = new Node(3);
    s1->next = s2;
    s2->next = s3;
    s3->next = s2;
    Node *copy_head = copy_single_list(s1);


    return 0;
}

