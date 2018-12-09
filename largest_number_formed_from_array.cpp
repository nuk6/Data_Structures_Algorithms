#include <bits/stdc++.h>
using namespace std;
int a[105];
//The function returns 1 when a should be placed first 
//and 2 when b should be placed first
//in case when both can b placed interchangeably like a = "12" b = "1212"
//then it returns 0;
int func(string a, string b)
{
    int m = a.size();
    int n = b.size();
    if(m == n)
    {
        for (int i = 0; i < m; ++i)
        {
            if(a[i] > b[i]) return 1;
            else if(b[i] > a[i]) return 2;
        }
        return 0;
    }
    int k = min(m,n);
    for (int i = 0; i < k; ++i)
    {
        if(a[i] > b[i]) return 1;
        else if(b[i] > a[i]) return 2;
    }
    if(m > n) return func(a.substr(k),b);
    else return func(a,b.substr(k));
}

bool cust(const int& a, const int& b)
{
    return(!(func(to_string(a),to_string(b)) > 1));
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a,a+n,cust);
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
        }cout << endl;
    }
    return 0;
}