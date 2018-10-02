//https://leetcode.com/problems/sort-characters-by-frequency/description/
struct record {
    char c;
    int times;
    record(char a,int t):c(a),times(t){}
};
bool operator<(const record r1, const record r2) {
    return r1.times < r2.times;
}
class Solution {
public:


    string frequencySort(string s) {
        string result;
        if (s.size() == 0)
            return result;
        int arr[256] = { 0 };
        priority_queue<record> pq;

        for (int i = 0; i < s.size(); i++){
            arr[s[i]]++;
        }

        for (int i = 0; i < 256; i++){
            if (arr[i] > 0){
                record s((char)i,arr[i]);
                pq.push(s);
            }
        }

        while (!pq.empty()){
            record r = pq.top();
            pq.pop();

            for (int i = 0; i < r.times; i++){
                result += r.c;
            }
        }
        return result;
    }
};