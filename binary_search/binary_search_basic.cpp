#include <bits/stdc++.h>
// https://www.nowcoder.com/test/question/66b68750cf63406ca1db25d4ad6febbf?pid=8537209&tid=17461769
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
const int MAXN = 305;
typedef long long LL;


struct Node {
    int prefer;
    int id;
};


bool sort_compare(const Node &a, const Node &b) {
    if (a.prefer != b.prefer) {
        return a.prefer < b.prefer; // prefer 小的排在前面
    } else {
        return a.id < b.id;
    }
}

struct equal_compare {
    bool operator()(const Node &a, int i) {
        return a.prefer < i; // 递增顺序
    }

    bool operator()(int i, const Node &b) {
        return i < b.prefer;
    }
};

struct find_second_cmp {
    bool operator()(const Node &a, int k) const {
        return a.id < k;
    }

    bool operator()(int k, const Node &b) const {
        return k < b.id;
    }
};

//    The idea is to do a binary search in the range from matrix[0][0] to matrix[n-1][n-1]. At each iteration, count numbers smaller than 'mid' in each row using binary search. If total count is too small, then search a larger mid, otherwise search a smaller mid.
//
//    The idea is not hard to understand, but the details should be clarified for you to have better understanding about binary search.
//    (i) why use upper_bound here, not lower_bound?
//    Ans: upper_bound find the first position where x > key, while lower_bound find the first position where x >= key. Here I want to get the count that how many entries in each row are smaller or equal to 'mid', if we use lower_bound, we will lose the part that are equal to 'mid'.
//    (ii) why search left with condition count < k, not count <= k ?
//    Ans: This is a common issue when it comes to binary search. Just keep in mind: when we quit the binary search, 'low' will point to the smallest position where the if-clause is not qualified (count >= k for this example here), and 'high' will point to the last position where if-clause is qualified (count < k for this example here). In this case, we want to find the smallest possible value which has count >= k, so we use (count < k) as the if-clause.


int kthSmallest(vector<vector<int>> &matrix, int k) {
    const int n = matrix.size();
    int low = matrix[0][0], high = matrix[n - 1][n - 1];
    while (low <= high) {
        int count = 0;
        int mid = low + (high - low) / 2;
        for (int row = 0; row < n; row++)
            count += upper_bound(matrix[row].begin(), matrix[row].end(), mid) - matrix[row].begin();
        if (count < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int n;
int q;
int q_l, q_r, q_k;

int main() {
    cin >> n;
    int a;
    vector<Node> records(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        Node node;
        node.prefer = a;
        node.id = i;
        records[i] = node;
    }
    sort(records.begin() + 1, records.end(), sort_compare);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> q_l >> q_r >> q_k;
        auto range = equal_range(records.begin() + 1, records.end(), q_k, equal_compare{});
        // 返回相等的区间的下标， 注意 是左闭右开， records.end() 是不包含相等的值的下标

        // upper 返回最后一个等于给定值的坐标，没有则是第一个大于给定值的坐标
        vector<Node>::iterator ans_r = upper_bound(range.first, range.second, q_r, find_second_cmp{});

        // lower 返回第一个等于给定值的坐标，没有则是第一个大于给定值的坐标

        vector<Node>::iterator ans_l = lower_bound(range.first, range.second, q_l, find_second_cmp{});
        int ans = ans_r - ans_l;
        cout << ans << endl;

    }
    return 0;

}

//
