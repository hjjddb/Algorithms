#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i=0; i<n; ++i) cin >> a[i][0] >> a[i][1];
    vector<int> dp(m+1);
    for(int i=0; i<n; ++i)
        for(int j=m; j>=a[i][0]; --j) dp[j]=max(dp[j], dp[j-a[i][0]]+a[i][1]);
    cout << dp[m];
}