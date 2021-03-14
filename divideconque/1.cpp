#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

int main(){
    int n;
    std::cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) std::cin >> a[i];
    std::cout << *max_element(a.begin(), a.end());
}