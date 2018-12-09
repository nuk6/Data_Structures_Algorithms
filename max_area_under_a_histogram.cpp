#include <bits/stdc++.h>
using namespace std;

int find(int a[], int n)
{
    stack<int> s;
    int i = 0,p,ar,mx;
    mx = INT_MIN;
    while(i < n)
    {
        if(s.empty()|| a[i] >= a[s.top()])
            s.push(i++);
        else
        {
            p = s.top(); s.pop();
            ar = a[p]*(s.empty()?i:i-s.top()-1);
            mx = max(mx,ar);
        }
    }
    while(!s.empty())
    {
        p = s.top(); s.pop();
            ar = a[p]*(s.empty()?i:i-s.top()-1);
            mx = max(mx,ar);
    }
    return mx;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout <<find(a,n)<<endl;
    }
	return 0;
}