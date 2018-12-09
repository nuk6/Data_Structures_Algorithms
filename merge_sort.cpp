#include <iostream>
using namespace std;
int a[100];


void merge(int a[], int l ,int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int x[n1],y[n2];
	for (int i = 0; i < n1; ++i) x[i] = a[l+i];
	for (int i = 0; i < n2; ++i) y[i] = a[m+1+i];
	int p = 0,q= 0,idx= l;
	while((p < n1)&&(q<n2))
	{
		if(x[p] < y[q]) a[idx++] = x[p++];
		else a[idx++] = y[q++];
	}
	while(p < n1) a[idx++] = x[p++];
	while(q < n2) a[idx++] = y[q++];
	
}

void merge_sort(int a[], int l ,int r)
{
	if(l < r)
	{
	int m = (l+r)>>1;
	merge_sort(a,l,m);
	merge_sort(a,m+1,r);
	merge(a,l,m,r);
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	merge_sort(a,0,n-1);
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	return 0;
}