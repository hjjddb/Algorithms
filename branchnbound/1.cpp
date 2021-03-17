#include<iostream>
#include<vector>

using namespace std;

int n, ans(INT_MAX);
vector<vector<int>> c;

void backtrack(int s, int id, int cost, int mask){
    for(int i=0; i<n; ++i) if ((1<<i) & mask){
        if (!((1<<i) ^ mask)) ans = min(ans, cost+c[id][i]+c[i][s]);
        else {
            if (cost<=ans){
                backtrack(s, i, cost+c[id][i], (1<<i) ^ mask);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; ++i) {
        vector<int> x(n);
        for(int j=0; j<n; ++j) cin >> x[j];
        c.push_back(x);
    }
    for(int i=0; i<n; ++i) backtrack(i, i, 0, ((1<<n)-1) ^ (1<<i));
    cout << ans;
}