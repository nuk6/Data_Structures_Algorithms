using namespace std;
int a[10001];

int prtn(int l, int r)
{
    int pvt = a[r];
    int i = l;
    for(int j = l; j < r; ++j)
    {
        if(a[j] < pvt)
        {
            swap(a[j],a[i++]);
        }
    }
    swap(a[i],a[r]); return i;
}

void quick_sort(int l, int r)
{
    if(l < r)
    {
        int m = prtn(l,r);
        quick_sort(l,m-1);
        quick_sort(m+1,r);
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
    int n; cin >> n; 
    for(int i = 0; i <n; ++i) cin >> a[i];
    quick_sort(0,n-1);
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    }
	return 0;
}