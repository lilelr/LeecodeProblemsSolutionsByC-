#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <list>//https://leetcode.com/problems/sentence-similarity-ii/description/
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))

// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
typedef long long LL;

const int maxn = 0x3f3f3f3f;


class Solution {
public:

    map<string, string> F; // 并查集

    string find(string x) {
        if (F.find(x) == F.end()) {
            F[x] = x;
            return x;
        }else if(F[x] == x){ // key和value 相等则返回 key， 避免死循环
            return x;
        } else{
            return find(F[x]); // 继续沿着父节点找
        }

    }

    bool
    areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<pair<string, string>> pairs) {
        int len1 = words1.size();
        int len2 = words2.size();
        if (len1 != len2) return false;

        for (pair<string, string> &item:pairs) {
            string &left = item.first;
            string &right = item.second;
            string root_l = find(left);
            string root_r = find(right);
            F[root_r] = root_l; // 把右节点的根设为 左节点的根，从而两棵树连在一起
//            cout<<""
        }

        bool flag = true;
        for (int i = 0; i < len1; i++) {
            string &w1 = words1[i];
            string &w2 = words2[i];
//            cout<<find(w1)<<" "<<find(w2)<<endl;
            if (w1 == w2) continue;
            if (F.find(w1) == F.end() || F.find(w2) == F.end()) {
                flag = false;
                break;
            }
            if (find(w1) != find(w2)) { // 根节点不一样，则不具备传递性
                cout << w1 << "  : " << w2 << endl;
                cout << find(w1) << ": " << find(w2) << endl;
                flag = false;
                break;
            }
        }
        return flag;
    }
};

int main() {
    vector<string> words1 = {"great","acting","skills"};
    vector<string> words2 = {"fine","drama","talent"};
    vector<pair<string,string>> pairs = {{"great","good"},{"fine","good"},{"drama","acting"},{"skills","talent"}};

//    vector<string> words1 = {"yesterday", "james", "have", "an", "extraordinary", "meal"};
//    vector<string> words2 = {"yesterday", "james", "take", "one", "good", "dinner"};
//    vector<pair<string, string>> pairs = {{"great",         "good"},
//                                          {"extraordinary", "good"},
//                                          {"well",          "good"},
//                                          {"wonderful",     "good"},
//                                          {"excellent",     "good"},
//                                          {"fine",          "good"},
//                                          {"nice",          "good"},
//                                          {"any",           "one"},
//                                          {"some",          "one"},
//                                          {"unique",        "one"},
//                                          {"the",           "one"},
//                                          {"an",            "one"},
//                                          {"single",        "one"},
//                                          {"a",             "one"},
//                                          {"truck",         "car"},
//                                          {"wagon",         "car"},
//                                          {"automobile",    "car"},
//                                          {"auto",          "car"},
//                                          {"vehicle",       "car"},
//                                          {"entertain",     "have"},
//                                          {"drink",         "have"},
//                                          {"eat",           "have"},
//                                          {"take",          "have"},
//                                          {"fruits",        "meal"},
//                                          {"brunch",        "meal"},
//                                          {"breakfast",     "meal"},
//                                          {"food",          "meal"},
//                                          {"dinner",        "meal"},
//                                          {"super",         "meal"},
//                                          {"lunch",         "meal"},
//                                          {"possess",       "own"},
//                                          {"keep",          "own"},
//                                          {"have",          "own"},
//                                          {"extremely",     "very"},
//                                          {"actually",      "very"},
//                                          {"really",        "very"},
//                                          {"super",         "very"}};
    Solution s;
    bool ans = s.areSentencesSimilarTwo(words1, words2, pairs);
    cout << ans << endl;
}