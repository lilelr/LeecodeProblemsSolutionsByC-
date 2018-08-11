
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


//#include<iostream>
//#include<vector>
//#include<set>
//#include <functional>
//
//using namespace std;
//
//int main()
//{
//    vector<int> data{1,4,3,8};
//    //vector<int> d1(data.begin()+1, data.begin() + 3);
//    multiset<int, greater<int> >  test;
//    for (int i = 0; i < data.size(); i++)
//    {
//        test.insert(data[i]);
//    }
////    return 0;
////}
//得到test的结果为 8,4,3,1。
//所以，添加greater<int> 会使得排序为降序排序。即更大的在前面。
//
//一般不加第二个参数，会默认为是less<int>，即按升序排序。

typedef multiset<int, greater<int>> int_set;
typedef multiset<int, greater<int>>::iterator set_iterator;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k || k < 1) {
            return vector<int>();
        }
        vector<int> ans(k);

        int_set tset;
        vector<int>::const_iterator iter = input.begin();
        for (; iter != input.end(); iter++) {
            if (tset.size() < k) {
                tset.insert(*iter);
            } else {
                set_iterator iter_greatest = tset.begin();
                if (*iter < *(tset.begin())) {
                    tset.erase(iter_greatest);
                    tset.insert(*iter);
                }
            }
        }
        copy(tset.begin(), tset.end(), ans.begin());
        return ans;

    }
};


int main() {

    vector<int> input = {4, 5, 7, 1, 2, 3};
    Solution s;
    vector<int> res = s.GetLeastNumbers_Solution(input, 3);
    for (int item:res) {
        cout << item << endl;
    }

}