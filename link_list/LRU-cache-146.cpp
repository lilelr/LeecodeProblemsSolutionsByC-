#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
using namespace std;
// https://leetcode.com/problems/lru-cache/description/
class LRUCache {
private:
    struct ListNode {
        int val;
        int key;
        ListNode *next;
        ListNode *pre;
        ListNode(int x,int y) : key(x),val(y), next(NULL),pre(NULL) { }
    };
    int capacity_;
    ListNode* head_;
    int cur_size_;
    ListNode* next_;
    ListNode* pre_;
    unordered_map<int,ListNode*> cache_map_;

public:

    LRUCache(int capacity) {
        this->capacity_ = capacity;
        this->head_ = new ListNode(0,0);
        this->head_->next = this->head_;
        this->head_->pre = this->head_;
        this->cur_size_ = 0;

    }

    int get(int key) {

        if(this->cache_map_.find(key) != this->cache_map_.end()){
//            cout<<tmp_node->val<<endl;
            ListNode* tmp_node = this->cache_map_.at(key);
            this->detach(tmp_node);
            this->insert_start_node(tmp_node);
//            cout<<tmp_node->val<<endl;
            return tmp_node->val;
        }else{
            return -1;
        }
    }

   
    void detach(ListNode* node){
        ListNode* pre_node = node->pre;
        ListNode* next_node = node->next;
        pre_node->next = next_node;
        next_node->pre = pre_node;
    }

    void put(int key, int val){
        if(this->capacity_  == 0) return;

        if(this->cache_map_.find(key) != this->cache_map_.end()){
            ListNode* tmp_node = this->cache_map_.at(key);
            this->detach(tmp_node);
            tmp_node->val = val;
            this->insert_start_node(tmp_node);
        } else{
            if(this->cur_size_ < this->capacity_){
                ListNode* newNode = new ListNode(key,val);
                this->cache_map_.insert({key,newNode});
                this->insert_start_node(newNode);
                this->cur_size_++;
            }else{
                ListNode* tail_node = this->remove_tail_node();
                this->cache_map_.erase(tail_node->key);
                tail_node->key = key;
                tail_node->val = val;
                this->insert_start_node(tail_node);
                this->cache_map_.insert({tail_node->key,tail_node});
            }
        }
    }

    void insert_start_node(ListNode* new_node){
        ListNode* old_start = this->head_->next;
        new_node->next = old_start;
        old_start->pre = new_node;
        this->head_->next = new_node;
        new_node->pre=this->head_;
    }

    ListNode* remove_tail_node(){
        ListNode* tail = this->head_->pre;
        ListNode* tail_pre = tail->pre;
        tail_pre->next = this->head_;
        this->head_->pre = tail_pre;
        tail->pre= nullptr;
        tail->next = nullptr;
        return tail;
    }

};

int main(){
    LRUCache lru_cache(3);
    lru_cache.put(1,-1);
    lru_cache.put(3,-3);
    int tmp_val = lru_cache.get(3);
    cout<<tmp_val<<endl;
    lru_cache.put(2,-2);
    lru_cache.put(4,-4);
    lru_cache.get(4);
    lru_cache.put(5,-5);

}
