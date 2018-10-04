#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
// accumulate example
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
using namespace std;

//https://leetcode.com/problems/replace-words/description/

class Solution {
public:
    struct Node{
        bool isLeaf;
        Node* children[26];
    };

    Node* getNode()
    {
        Node* temp=new Node;
        temp->isLeaf=false;
        for(int i=0;i<26;i++)
        {
            temp->children[i]=NULL;
        }
        return temp;

    }

    void insert(Node* root, string val)
    {
        int index;
        Node* curr=root;
        int j=0;
        for(j=0;j<val.length();j++)
        {
            index=val[j]-'a';
            if(curr->children[index]==NULL)
            {
                curr->children[index]=getNode();
            }
            curr=curr->children[index];
        }
        curr->isLeaf=true;
        return;

    }

    string shortestPrefix(Node* root, string value)
    {
        Node* curr=root;
        string ans="";
        int i;
        int j=0;
        while(curr->isLeaf==false && j<value.length())
        {
            i=value[j]-'a';
            if(curr->children[i]==NULL)return "";
            curr=curr->children[i];
            ans+=value[j];
            j++;
        }
        if(curr->isLeaf==false)return "";
        return ans;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        Node* root=getNode();
        for(string i:dict)insert(root,i);
        stringstream st(sentence);
        string word;
        string a,ans="";
        while(st>>word)
        {
            a=shortestPrefix(root,word);
            if(a=="")
                ans+=word+" ";
            else ans+=a+" ";
        }

        if(ans.length()>0)ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};

int main() {

}