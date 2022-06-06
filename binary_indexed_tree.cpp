#include<bits/stdc++.h>
using namespace std;
using cvi = const vector<int>&;
const int MX = 20007;
int bit[MX];

void add(int pos, int v, int n) {
	for(int i = pos+1; i <= n; i += (i&-i)) bit[i] += v;
}

void build(cvi a) {
	int n = a.size();
	for(int i = 0; i < n; ++i) {
		add(i, a[i], n);
	}
}

int query(int x, int y) {
	int val1= 0, val2 = 0;
	for(int i = x; i; i -= (i&-i)) {
		val1 += bit[i];
	} 
	for(int i = y; i; i -= (i&-i)) {
		val2 += bit[i];
	} 
	return val2 - val1;
}

int main() {
	vector<int> a{1,2,-1,5,2};
	build(a);
	cout << query(2,4);
}
