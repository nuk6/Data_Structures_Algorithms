#include<bits/stdc++.h>
using namespace std;
const int N = 100, K = 100;
int n,k,t,dp[N][K+1];
void solve(){
    //cout << "Hi";
    for(int i = 0; i <= K; ++i) dp[0][i] = i;
    for(int i = 1; i < N; ++i) {dp[i][0] = 0; dp[i][1] = 1;}
    for(int i = 1; i < N;++i){
        for(int j = 2; j <= K; ++j){
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; ++x){
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
            }
        }
    }
}

int main(){
    solve();
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << dp[n-1][k] << endl;
    }
    return 0;
}
