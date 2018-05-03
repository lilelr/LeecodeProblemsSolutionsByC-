// 有一个单向链表，可能有环也可能无环，请把这个链表复制一份

// 阿里巴巴面试题

// 判断一个链表有否有环。有的话求出链表长度、环长度和连接点。
//给定一个单链表，只给出头指针h：
//
//1、如何判断是否存在环？
//
//2、如何知道环的长度？
//
//3、如何找出环的连接点在哪里？
//
//4、带环链表的长度是多少？
//解法：
//
//1、对于问题1，使用追赶的方法，设定两个指针slow、fast，从头指针开始，每次分别前进1步、2步。如存在环，则两者相遇；如不存在环，fast遇到NULL退出。
//
//2、对于问题2，记录下问题1的碰撞点p，slow、fast从该点开始，再次碰撞所走过的操作数就是环的长度s。
//
//3、问题3：有定理：碰撞点p到连接点的距离=头指针到连接点的距离，因此，分别从碰撞点、头指针开始走，相遇的那个点就是连接点。(证明在后面附注)
//
//4、问题3中已经求出连接点距离头指针的长度，加上问题2中求出的环的长度，二者之和就是带环单链表的长度


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

