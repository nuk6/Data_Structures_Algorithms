#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+100;
int n;
LL sum[N];
LL ans=0;
LL t;
void Solve(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	Solve(l,mid);
	Solve(mid+1,r);
	LL ret=0;
	for(int i=l,j=mid;i<=mid;++i){
		while(j<r&&sum[j+1]-sum[i]==t)j++;
		ret+=j-mid;
	}
	ans+=ret;
	inplace_merge(sum+l,sum+mid+1,sum+r+1);
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;++i){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}	
	Solve(0,n);
	cout<<ans;
}