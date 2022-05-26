#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using pii = pair<int,int>;
using umii = unordered_map<int,int>; 
vector<int> graph[100];
int a[100]; // 0 = unexplored , 1 = exploring , 2 = explored

bool dfs(int i) {
	if(a[i] == 1) return true;
	a[i] = 1;
	for(int v : graph[i]) {
		if(a[v] != 2)
			if(dfs(v)) return true;
	}
	a[i] = 2;
	return false;
}

bool hasCycle() {
	for (int i = 1; i <= 3; ++i) 
		if(a[i] != 2 && dfs(i))
			return true;
	return false;
}


int main() {
	vector<pii> edges{{1,2}, {2,3}, {3,1}};
	for(const pii& e : edges) {
		graph[e.first].push_back(e.second);
	}
	cout << ((hasCycle()) ? "has cycle" : "nope" );
	return 0;
}
