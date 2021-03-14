#include<iostream>
#include<vector>

using namespace std;
 
void merge(vector<int> &a, int l, int m, int r)
{
    int n1(m-l+1);
    int n2(r-m); 
    vector<int> b(n1), c(n2);
 
    for(int i=0; i<n1; i++) b[i] = a[l+i];
    for(int i=0; i<n2; i++) c[i] = a[m+1+i];
 
    int i(0), j(0), k(l);
    while (i<n1 && j<n2){
        if (b[i] <= c[j]) a[k] = b[i++];
        else a[k] = c[j++];
        k++;
    }
 
    while (i < n1){
        a[k] = b[i];
        i++;
        k++;
    }
 
    while (j<n2){
        a[k] = c[j];
        j++;
        k++;
    }
}
 
void mergeSort(vector<int> &a, int l, int r){
    if (l<r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    mergeSort(a, 0, n-1);
    for(int i=0; i<n; ++i) cout << a[i] << " ";
    return 0;
}
 