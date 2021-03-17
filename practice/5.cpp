#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void input(vector<int> &a){
    for(int i=0; i<a.size(); ++i) cin >> a[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m, ans(0);
    cin >> n >> m;
    vector<int> a(n), b(m);
    input(a);
    input(b);
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j){
        dp[i+1][j+1]= dp[i][j]+(a[i]==b[j]);
        ans=max(ans, dp[i+1][j+1]);
    }
    cout << ans;
}