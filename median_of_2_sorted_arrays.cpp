#include<bits/stdc++.h>
using namespace std;

double get(const vector<int>& a, const vector<int>& b) {
	if(a.size() > b.size()) return get(b, a);
	int m = a.size(), n = b.size();
	int t = -1;
	int elems = (m+n-1)/2 + 1; // 4
	int d = elems - 1; 
	//cout << "*" << b[d] << " " << a[t+1] << endl;
	while((t+1 < m && t > 0 && d != 0) && b[d] > a[t+1]) {
		d = (d)/2;
		t = elems - (d+1) -1;
		cout << "T =" << t << endl;
	}
	cout << "Hi\n";
	double ans;
	if((m+n)%2 == 1) {
		ans = max(b[d], a[t]);
	} else {
		double sum;
		if(t!=-1) sum = (max(b[d],a[t]) + min(b[d+1], a[t+1]));
		else sum = b[d] + min(a[t+1], ((d+1 < n) ? b[d+1] : INT_MAX));
		ans = sum/2;
	}
	return ans;
}

void print(const vector<int>& a) {
	for(auto it : a) { cout << it; }
	cout << endl;
}

int main() {
	vector<int> a{2};
	vector<int> b{1,3};
	cout << "Ans =" << get(a,b) << endl;
}
