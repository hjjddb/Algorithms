#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m(1);
    cin >> n;
    vector<int> a(n), b(n+1, INT_MAX), c(n), dp(n+1);
    b[0]=0;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i){
        int x=lower_bound(b.begin(), b.begin()+m+1, a[i])-b.begin();
        m=max(m, x);
        c[i]=x;
        b[x]=min(b[x], a[i]);
    }
    vector<int> ans;
    int e(m); --n;
    while(e&&n>=0){
        if (c[n]==e) --e, ans.push_back(a[n]);
        --n; 
    }
    for(int i=m-1; i>=0; --i) cout << ans[i] << " ";
}