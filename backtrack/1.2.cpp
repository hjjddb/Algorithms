#include<iostream>
#include<vector>

int n, k;
std::vector<int> res;
std::vector<bool> c;

void backtrack(int id){
    for(int i=0; i<n; ++i) if (!c[i]){
        res[id]=i+1;
        c[i]=1;
        if (id==k-1) for(int j=0; j<res.size(); ++j) std::cout << res[j] << " \n"[j==res.size()-1];
        else backtrack(id+1);
        res[id]=0;
        c[i]=0;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    std::cin >> n >> k;
    res.resize(k);
    c.resize(n);
    backtrack(0);
}