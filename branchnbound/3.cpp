#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, k, q;
    cin >> n >> k >> q;
    int a[n], b[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) b[(i+k)%n]=a[i];
    while(q--){
        int x;
        cin >> x;
        cout << b[x] << "\n";
    }
}