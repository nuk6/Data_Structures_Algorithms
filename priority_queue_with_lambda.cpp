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
	for (int i = 1; i <= 10; ++i) 	
		if(a[i] == 0 && dfs(i))
			return true;
	return false;
}

bool fn(int a, int b) { 
		return a > b; 
}

int main() {
	auto comp = [](int a, int b) -> bool { return a < b; };
	priority_queue<int, vector<int>, decltype(comp)> pq(comp);
	for (int i = 0; i < 10; ++i)
	{
		pq.push(i);
	}
	//pq.push_back
	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
