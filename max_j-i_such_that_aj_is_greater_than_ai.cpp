#include<iostream>
using namespace std;
int t,n;
int main() {
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    int a[n],r[n];
	    for(int i = 0; i < n; ++i) cin >> a[i]; r[n-1] = a[n-1];
	    for(int i = n-2; i >=0; --i) r[i] = max(r[i+1],a[i]);
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
