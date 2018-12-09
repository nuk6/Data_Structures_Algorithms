#include <iostream>
using namespace std;

int process(string s)
{
    int lps[100005];
    for(int i = 0; i < 100005; ++i) lps[i] = 0;
    int n = s.size(),mx = 0;
    lps[0] = 0;
    int i = 0,j = 1;
    while(j < n)
    {
        if(s[i]==s[j])
        {
            i++;
            lps[j] = i;
            mx = max(mx,lps[j]);
            j++;
        }
        else 
        {
            if(i > 0) i = lps[i-1];
            else j++;
        }
    }
    return lps[n-1];
}

int main()
{
    int t; string s; cin >> t;
    while(t--)
    {
        cin >> s;
        cout << process(s) << endl;
    }
    return 0;
}