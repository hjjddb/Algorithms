#include<iostream>
#include<vector>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

void read(vvi &x){
    for(int i=0; i<x.size(); ++i) for(int j=0; j<x[i].size(); ++j) cin >> x[i][j];
}

void write(const vvi &x){
    for(int i=0; i<x.size(); ++i) for(int j=0; j<x[i].size(); ++j) cout << x[i][j] << " \n"[j==x[i].size()-1];
}

vvi subMatrix(const vvi &x, const int &r, const int &c, const int &nr, const int &nc){
    vvi res(nr, vi(nc));
    for(int i=0; i<nr; ++i) for(int j=0; j<nc; ++j) res[i][j]=x[r+i][c+j];
    return res;
}

vvi operator + (vvi a, const vvi &b){
    for(int i=0; i<a.size(); ++i) for(int j=0; j<a[i].size(); ++j) a[i][j]+=b[i][j];
    return a;
}

vvi operator - (vvi a, const vvi &b){
    for(int i=0; i<a.size(); ++i) for(int j=0; j<a[i].size(); ++j) a[i][j]-=b[i][j];
    return a;
}

vvi matrixMultiplication(const vvi &a, const vvi &b, int n){
    if (n==1) return vvi(1, vi(1, a[0][0]*b[0][0]));
    vvi C(n, vi(n));
    n>>=1;
    
    vvi A[2][2], B[2][2];
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
        A[i][j].resize(n);
        B[i][j].resize(n);
        for(int r=0; r<n; ++r){
            A[i][j][r].resize(n);
            B[i][j][r].resize(n);
            for(int c=0; c<n; ++c){
                A[i][j][r][c]=a[i*n+r][j*n+c];
                B[i][j][r][c]=b[i*n+r][j*n+c];
            }
        }
    }

    vvi X[8];
    X[0] = matrixMultiplication(A[0][0], B[0][0], n);
    X[1] = matrixMultiplication(A[0][1], B[1][0], n);
    X[2] = matrixMultiplication(A[0][0], B[0][1], n);
    X[3] = matrixMultiplication(A[0][1], B[1][1], n);
    X[4] = matrixMultiplication(A[1][0], B[0][0], n);
    X[5] = matrixMultiplication(A[1][1], B[1][0], n);
    X[6] = matrixMultiplication(A[1][0], B[0][1], n);
    X[7] = matrixMultiplication(A[1][1], B[1][1], n);

    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
        for(int r=0; r<n; ++r) for(int c=0; c<n; ++c){
            C[r+i*n][c+j*n]=X[(i<<2)+(j<<1)][r][c]+X[((i<<2)+(j<<1))|1][r][c];
        }
    }
    return C;
}

vvi strassen(const vvi &a, const vvi &b, int n){
    if (n==1) return vvi(1, vi(1, a[0][0]*b[0][0]));    vvi C(n, vi(n));
    n>>=1;
    
    vvi A[2][2], B[2][2];
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
        A[i][j].resize(n);
        B[i][j].resize(n);
        for(int r=0; r<n; ++r){
            A[i][j][r].resize(n);
            B[i][j][r].resize(n);
            for(int c=0; c<n; ++c){
                A[i][j][r][c]=a[i*n+r][j*n+c];
                B[i][j][r][c]=b[i*n+r][j*n+c];
            }
        }
    }

    vvi P[8];
    P[0] = matrixMultiplication(A[0][0], B[0][1]-B[1][1], n);
    P[1] = matrixMultiplication(A[0][0]+A[0][1], B[1][1], n);
    P[2] = matrixMultiplication(A[1][0]+A[1][1], B[0][0], n);
    P[3] = matrixMultiplication(A[1][1], B[1][0]-B[0][0], n);
    P[4] = matrixMultiplication(A[0][0]+A[1][1], B[0][0]+B[1][1], n);
    P[5] = matrixMultiplication(A[0][1]-A[1][1], B[1][0]+B[1][1], n);
    P[6] = matrixMultiplication(A[0][0]-A[1][0], B[0][0]+B[0][1], n);

    for(int r=0; r<n; ++r) for(int c=0; c<n; ++c){
        C[r][c]=P[4][r][c]+P[3][r][c]-P[1][r][c]+P[5][r][c];
        C[r][c+n]=P[0][r][c]+P[1][r][c];
        C[r+n][c]=P[3][r][c]+P[2][r][c];
        C[r+n][c+n]=P[0][r][c]+P[4][r][c]-P[2][r][c]-P[6][r][c];
    }
    return C;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    vvi a(n, vi(n)), b(n, vi(n));
    read(a);
    read(b);
    vvi c = matrixMultiplication(a, b, n);
    vvi d = strassen(a, b, n);
    write(c);
    write(d);
}