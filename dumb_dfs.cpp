#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using umii = unordered_map<int,int>; 

const int MX = 100;
unordered_map<int, bool> vis;
vector<int> graph[MX];

void dfs(int i) {
	if(!vis[i]) {
		vis[i] = true;
		cout << i << " -> ";
		for(auto u : graph[i]) {
			dfs(u);
		}
	}
	cout << endl;
}

int main() {
	vector<pair<int, int>> edges{{1,5}, {1,6}, {5,6}, {6,4}, {2,1}, {3,2}, {3,4}, {7,3}, {7,4}};
	for(auto it : edges) {
		graph[it.first].push_back(it.second);
	}
	for(int i = 7 ; i > 0; --i){
		if(!vis[i])
			dfs(i);
	}
	return 0;
}
