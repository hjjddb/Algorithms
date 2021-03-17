#include<iostream>
#include<vector>

using namespace std;

int n, m, ans, mask;
vector<int> w, v;

void backtrack(int id, int _mask, int _w, int _v){
    if (ans<_v) ans=_v, mask=mask;
    for(int i=0; i<2; ++i){
        if (i){
            if (_w+w[id]<=m&&id<n) backtrack(id+1, 1<<id|_mask, _w+w[id], _v+v[id]);
        } else if (id<n) backtrack(id+1, _mask, _w, _v);
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    w.resize(n), v.resize(n);
    for(int i=0; i<n; ++i) cin >> w[i] >> v[i];
    backtrack(0, 0, 0, 0);
    cout << ans << '\n';
    for(int i=0; i<n; ++i) if (1<<i&mask) cout << i << " ";
}