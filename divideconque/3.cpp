#include<iostream>
#include<vector>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void write(const vvi &a){
    for(int i=0; i<a.size(); ++i) for(int j=0; j<a[i].size(); ++j) cout << a[i][j] << " \n"[j==a[i].size()-1];
}

int count(1);

void tile(vvi &a, int x0, int y0, int n, int x, int y){
    if (n==2){
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
            int nx(x0+i), ny(y0+j);
            if (nx!=x||ny!=y) a[nx][ny]=count;
        }
        ++count;
        return;
    }
    n>>=1;
    int res(0);
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
        int x1(x0+i*n), y1(y0+j*n);
        if (x1<=x&&x<x1+n && y1<=y&&y<y1+n) res=((i<<1)|j);
    }
    switch (res){
    case 0:
        a[x0+n-1][y0+n]=count;
        a[x0+n][y0+n-1]=count;
        a[x0+n][y0+n]=count;
        ++count;
        tile(a, x0, y0, n, x, y);
        tile(a, x0, y0+n, n, x0+n-1, y0+n);
        tile(a, x0+n, y0, n, x0+n, y0+n-1);
        tile(a, x0+n, y0+n, n, x0+n, y0+n);
        break;
    case 1:
        a[x0+n-1][y0+n-1]=count;
        a[x0+n][y0+n-1]=count;
        a[x0+n][y0+n]=count;
        ++count;
        tile(a, x0, y0, n, x0+n-1, y0+n-1);
        tile(a, x0, y0+n, n, x, y);
        tile(a, x0+n, y0, n, x0+n, y0+n-1);
        tile(a, x0+n, y0+n, n, x0+n, y0+n);
        break;
    case 2:
        a[x0+n-1][y0+n-1]=count;
        a[x0+n-1][y0+n]=count;
        a[x0+n][y0+n]=count;
        ++count;
        tile(a, x0, y0, n, x0+n-1, y0+n-1);
        tile(a, x0, y0+n, n, x0+n-1, y0+n);
        tile(a, x0+n, y0, n, x, y);
        tile(a, x0+n, y0+n, n, x0+n, y0+n);
        break;
    case 3:
        a[x0+n-1][y0+n-1]=count;
        a[x0+n-1][y0+n]=count;
        a[x0+n][y0+n-1]=count;
        ++count;
        tile(a, x0, y0, n, x0+n-1, y0+n-1);
        tile(a, x0, y0+n, n, x0+n-1, y0+n);
        tile(a, x0+n, y0, n, x0+n, y0+n-1);
        tile(a, x0+n, y0+n, n, x, y);
        break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, x, y;
    cin >> n >> x >> y, --x, --y;
    n = (1<<n);
    vvi a(n, vi(n));
    tile(a, 0, 0, n, x, y);
    write(a);
}