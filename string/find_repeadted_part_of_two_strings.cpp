#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//abcde cdefg
//
//eeefffwqerwq  wqerwq
//
//abcdeh cdefg


//get kmp table
int* get_kmp_table(const char *p, int n)
{
    if(p == NULL || n <= 0) return NULL;
    int *pr = new int[n];
    memset(pr, -1, sizeof(int)*n);
    int k = -1;
    for(int i  = 1; i < n; i++)
    {
        while(k > -1 && p[k+1] != p[i]) k = pr[k];
        if(p[k+1] == p[i]) k = k+1;
        pr[i] = k;
    }//for
    return pr;
}

//返回两个字符串的前后重叠的最长子串的长度
int fun(const char* p, int n, const char* s, int m)
{
    if(p == NULL || n <= 0 || s == NULL || m <= 0) return 0;
    int *pr = get_kmp_table(s, m);
    int k = -1;
    for(int i = 0; i < n; i++)
    {
        while(k > -1 && s[k+1] != p[i]) k = pr[k];
        if(s[k+1] == p[i]) k = k+1;

        if(i != n-1 && k == m-1) k = pr[m-1];
    }
    delete[] pr;
    return k+1;
}//LCS

int main()
{
    string str1;
    string str2;
//    while(cin >> p >> s)
//    {
    cin>>str1>>str2;
    int l1 = fun(str1.c_str(), str1.size(), str2.c_str(), str2.size());
    int l2 = fun(str2.c_str(), str2.size(), str1.c_str(), str1.size());
    int ans;
    if(l1 > l2){
        ans = l1;
    }else{
        ans = l2;
    }

    cout<<ans<<endl;

    char* astr= "123";
    cout<<&astr<<endl;
    cout<<&astr+1<<endl;
    cout<<astr+1<<endl;
    return 0;
}