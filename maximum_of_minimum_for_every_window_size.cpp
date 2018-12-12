#include <bits/stdc++.h>
using namespace std;
int n,a[101],l[101],r[101],ans[101],t;

void solve()
{
	stack<int> stk;
	stk.push(-1);stk.push(0);
	l[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		while((stk.size() > 1) && (a[i] <= a[stk.top()])) stk.pop();
		l[i] = stk.top();stk.push(i);
	}
	while(!stk.empty()) stk.pop();
	stk.push(n);stk.push(n-1);r[n-1] = n;
	for(int i = n-2; i >= 0;--i)
	{
		while((stk.size() > 1)&&( a[i] <= a[stk.top()])) stk.pop();
		r[i] = stk.top(); stk.push(i);
	}
	// for (int i = 0; i < n; ++i) cout << l[i] << " "; cout << endl;
	// for (int i = 0; i < n; ++i) cout << r[i] << " "; cout << endl;
	// for (int i = 0; i < n; ++i) cout << r[i]-l[i]-1 << " "; cout << endl;
	for (int i = 0; i < n+1; ++i) ans[i] = 0;
	for (int i = 0; i < n; ++i) ans[r[i]-l[i]-1] = max(ans[r[i]-l[i]-1],a[i]);
	for (int i = n-1; i >= 0; --i) ans[i] = max(ans[i],ans[i+1]);
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}

int main()
{
	cin >> t;
	while(t--){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	solve(); cout << endl;}
	return 0;
}