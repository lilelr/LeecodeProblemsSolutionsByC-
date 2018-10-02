#include <bits/stdc++.h>
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
//https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/93167/Concise-C++-19ms-solution-beating-99.4
// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
typedef long long LL;

const int maxn = 0x3f3f3f3f;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }

    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }

    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.

        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;

        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};


int main() {

    return 0;
}