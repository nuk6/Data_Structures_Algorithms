class Solution {
public:
    int MX = INT_MAX;
int MN = -1 * MX;
    double get(const vector<int>& a, const vector<int>& b) {
	if(a.size() > b.size()) return get(b,a);
    if(b.size() == 1) return (double) b[0];
	int n = a.size(), m = b.size();
	int l = 0, r = n, c1, c2, l1, l2, r1, r2;
	while(l <= r) {
		c1 = (l+r)/2;
		c2 = (m+n+1)/2 - c1;
		l1 = c1 == 0 ? MN : a[c1-1];
		l2 = c2 == 0? MN : b[c2-1];
		r1 = c1 == n? MX : a[c1];
		r2 = c2 == m? MX : b[c2];
		if(l1 < r2 && l2 < r1) {
			return ((m+n)%2 == 1) ? max(l1,l2) : ((max(l1,l2) + min(r1,r2))/2.0);
		}
		if(l1 > r2) {
			r = c1-1;
		} else {
			l = c1+1;
		}
	}
	return ((m+n)%2 == 1) ? max(l1,l2) : ((max(l1,l2) + min(r1,r2))/2.0);
}
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        return get(v1,v2);
    }
};
