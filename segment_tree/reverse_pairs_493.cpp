
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
class BinarySearchTreeSolution {
public:


    int reversePairs(vector<int> &nums) {
        int res = 0;
        Node *root = nullptr;
        for (int ele:nums) {
            res += search(root, 2L * ele + 1);
            root = insert(root, ele);
        }
    }

private:
    // Binary search tree
    struct Node {
        int val;
        int cnt;
        Node *left;
        Node *right;

        Node(int v) : val(v) {
            cnt = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    int search(Node *root, long val) {
        if (root == nullptr) {
            return 0;
        } else if (val == root->val) {
            return root.cnt;
        } else if (val > root->val) {
            return search(root, root->right);
        } else {
            return root->cnt + search(root, root->left);
        }
    }

    Node *insert(Node *root, int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else if (val == root->val) {
            root->cnt++;
        } else if (val > root->val) {
            root->cnt++;
            root->right = insert(root->right, val);
        } else {
            root->left = insert(root->left, val);
        }
        return root;
    }
};

// https://leetcode.com/problems/reverse-pairs/discuss/97270/10-lines-C++-accepted-using-binary-search
// 10 lines C++ accepted using binary search
class BinarySearchSolution {
public:
    int reversePairs(vector<int> &nums) {
        vector<int> sortedNums;
        int res = 0, target = 0, pos = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            target = nums[i] > 0 ? (nums[i] - 1) / 2 : nums[i] / 2 - 1;
            // find the target that is approximately nums[i]/2 in the sorted array
            auto ptr = upper_bound(sortedNums.begin(), sortedNums.end(), target);
            res += ptr - sortedNums.begin();
            // the number of reverse pair for nums[i] (j > i elements in nums are already sorted in "sortedNums")
            pos = upper_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
            // insert nums[i] in "sortedNums"
            sortedNums.insert(sortedNums.begin() + pos, nums[i]);
        }
        return res;
    }
};

class RedBlackTreeSolution {
    static const bool BLACK = false, RED = true;

    struct Node {
        long long key;
        Node *left, *right;
        size_t N;
        bool color;

        Node(long long k) : key(k), left(0), right(0), N(1), color(RED) {}

        ~Node() {
            delete left;
            delete right;
        }
    };

    void insert(long long key) {
        if (root) root->color = BLACK;
        root = insert(root, key);
    }

    size_t rank(long long key) const { return rank(root, key); }

    Node *insert(Node *x, long long key) {
        if (!x) return new Node(key);
        if (key < x->key) x->left = insert(x->left, key);
        else if (key > x->key) x->right = insert(x->right, key);
        ++x->N;
        if (is_red(x->right) && !is_red(x->left)) x = rotate_left(x);
        if (is_red(x->left) && is_red(x->left->left)) x = rotate_right(x);
        if (is_red(x->left) && is_red(x->right)) flip_color(x);
        return x;
    }

    size_t rank(const Node *x, long long key) const {
        if (!x) return 0;
        if (key >= x->key) return rank(x->right, key);
        return rank(x->left, key) + size(x) - size(x->left);
    }

    Node *rotate_left(Node *x) {
        auto y = x->right;
        size_t x_lt = size(x) - size(x->right);
        x->N = x->N - size(y) + size(y->left);
        y->N += x_lt;
        y->color = x->color;
        x->color = RED;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node *rotate_right(Node *x) {
        auto y = x->left;
        size_t x_rt = size(x) - size(x->left);
        x->N = x->N - size(y) + size(y->right);
        y->N += x_rt;
        y->color = x->color;
        x->color = RED;
        x->left = y->right;
        y->right = x;
        return y;
    }

    void flip_color(Node *x) {
        x->color = RED;
        x->left->color = x->right->color = BLACK;
    }

    size_t size(const Node *x) const {
        return x ? x->N : 0;
    }

    bool is_red(const Node *x) const {
        return x ? x->color : false;
    }

    Node *root = nullptr;
public:
    int reversePairs(vector<int> &nums) {
        int ret = 0;
        for (long long num : nums) {
            ret += rank(2 * num);
            insert(num);
        }
        return ret;
    }
};


