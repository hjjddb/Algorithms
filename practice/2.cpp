#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n), res(n);
    for(int i=0; i<n; ++i) cin >> a[i].first >> a[i].second;
    vector<int> b(1, 0);
    for(int i=0; i<n; ++i){
        int x=upper_bound(b.begin(), b.end(), a[i].first)-b.begin();
        if (x==b.size()) res[b.size()]=a[i], b.push_back(a[i].second);
        else {
            if (b[x]>a[i].second) b[x]=a[i].second, res[x]=a[i];
        }
    }
    cout << b.size()-1 << '\n';
    for(int i=1; i<b.size(); ++i) cout << res[i].first << " " << res[i].second << '\n';
}