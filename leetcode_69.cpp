#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using cvi = const vi&;
using cvs = const vector<string>&;
using pii = pair<int,int>;

// Returns the idx just greater & returns the idx less or equal
int searchRow(const vector<vector<int>>& mtx, int row, int target) {
	int cols = mtx[0].size();
	int l = 0, h = cols-1, mid;
	while(l < h) {
		mid = (l+h) >> 1;
		if(mtx[row][mid] > target) {
			h = mid;
		} else {
			l = mid+1;
		}
	}
	if(mtx[row][h] < target) return cols;
	return h-(mtx[row][h] != target);
}

int searchCol(const vector<vector<int>>& mtx, int col, int target) {
	int rows = mtx.size();
	int l = 0,h = rows-1, mid;
	while(l < h) {
		mid = (l+h) >> 1;
		if(mtx[mid][col] > target) {
			h = mid;
		} else {
			l = mid+1;
		}
	}
	if(mtx[h][col] < target) return rows;
	return h - (mtx[h][col] != target);
}

int main() {
	vector<vector<int>> mtx{{1,2,3},{4,5,7},{6,7,8}};
	cout << searchCol(mtx,2,6);
}
