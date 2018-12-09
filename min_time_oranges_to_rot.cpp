#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],n,m;
pair<int,int> coor;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
bool isVal(int a, int b)
{
	return((a >= 0)&&(a < m)&&(b >= 0)&&(b < n));
}

int main()
{
	int t; cin >> t;
	while(t--){
	queue<pair<int,int>> q;
	cin >> m >> n;
	int c1 = 0;
	for (int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] == 2)
				q.push(make_pair(i,j));
			else if(a[i][j] == 1) c1++;
		}
	}
	if(q.empty()){cout << -1; return 0;}
	else q.push(make_pair(-1,-1));
	int ans = 0,c11 = 0;
	while(!q.empty())
	{
		coor = q.front(); q.pop();
		if(coor.first == -1)
		{
			if(!q.empty())
			{
				q.push(make_pair(-1,-1));
				ans++;
			}
		}
		else
		{
			for(pair<int,int> d : dir)
			{
				int ni = coor.first + d.first;
				int nj = coor.second + d.second;
				if(isVal(ni,nj) && (a[ni][nj] == 1))
				{
					c11++;
					a[ni][nj] = 2;
					q.push(make_pair(ni,nj));
				}
			}
		}
	}
	if(c1-c11 > 0) cout << -1;
	else cout << ans;
	cout << endl;}
	return 0;
}