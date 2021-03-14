#include<iostream>
#include<vector>

using namespace std;
 
int partition(vector<int> &a, int low, int high){
    int pivot(a[high]), left(low), right(high-1);
    while(1){
        while(left <= right && a[left] < pivot) left++;
        while(right >= left && a[right] > pivot) right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}

void quickSort(vector<int> &a, int low, int high){
    if (low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
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
    quickSort(a, 0, n-1);
    for(int i=0; i<n; ++i) cout << a[i] << " ";
    return 0;
}