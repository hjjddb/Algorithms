#include<iostream>
#include<vector>

int n, k;
std::vector<int> res;

void backtrack(int x){
    for(int i=1; i<=std::min(x, k); ++i){
        res.push_back(i);
        if (x-i){
            backtrack(x-i);
        } else {
            for(int j=0; j<res.size(); ++j) std::cout << res[j] << " ";
            std::cout << '\n';
        }
        res.pop_back();
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    std::cin >> n >> k;
    backtrack(n);
}