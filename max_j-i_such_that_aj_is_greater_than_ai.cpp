#include<iostream>
using namespace std;
typedef int ll;
ll t,n;
int main() {
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    ll a[n],r[n];
	    for(ll i = 0; i < n; ++i) cin >> a[i]; r[n-1] = a[n-1];
	    for(ll i = n-2; i >=0; --i) r[i] = max(r[i+1],a[i]);
	    int i = 0, j= 0, ans = -1;
	    while(i < n && j < n)
	    {
	        if(r[j] >= a[i])
	        {
	            ans = max(ans, j-i);
	            j++;
	        }
	        else i++;
	    }
	    cout << ans << endl;
	}
	return 0;
}
