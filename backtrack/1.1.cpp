#include<iostream>

int n, k; 

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);


    std::cin >> n >> k;
    for(int i=0; i<(1<<n); ++i){
        if (__builtin_popcount(i)==k){
            for(int j=0; j<n; ++j) if (i&(1<<j)) std::cout << j+1 << " ";
            std::cout << '\n';
        }
    }
}