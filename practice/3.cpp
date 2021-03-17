#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, mx(0);
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0; i<n; ++i){
        for(int j=0; j<3; ++j) cin >> a[i][j];
        mx=max(mx, a[i][1]);
    }
    sort(a.begin(), a.end());
    vector<int> dp(mx+1);
    int p(0);
    for(int i=0; i<n; ++i){
        for(int j=1; j<a[i][0]; ++j) dp[j]=max(dp[j], dp[j-1]);
        dp[a[i][1]]=max(dp[a[i][1]], dp[a[i][0]-1]+a[i][2]);
        p=a[i][0];
    }
    cout << *max_element(dp.begin(), dp.end());
}