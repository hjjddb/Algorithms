#include<iostream>
#include<vector>

using std::cin;
using std::cout;

int n;
std::vector<int> res;

void backtrack(int x){
    for(int i=1; i<=x; ++i){
        res.push_back(i);
        if (x-i) backtrack(x-i);
        else {
            for(int j=0; j<res.size(); ++j) cout << res[j] << " ";
            cout << '\n';
        }
        res.pop_back();
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    backtrack(n);
}