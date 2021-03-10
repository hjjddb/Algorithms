#include<iostream>
#include<vector>
#include<string>

using std::vector;

vector<vector<int>> a(9, vector<int>(9));
vector<vector<bool>> r(10, vector<bool>(10)), c(10, vector<bool>(10)), z(10, vector<bool>(10));
bool flag;

void backtrack(int x, int y){
    if (flag) return;
    if (a[x][y]){
        if (x==y&&y==8){
            flag=1;
            return;
        } else {
            if (y==8) backtrack(x+1, 0);
            else backtrack(x, y+1);
        }
    }
    for(int i=1; i<10; ++i){
        if (!r[x][i]&&!c[y][i]&&!z[x%3+y%3][i]){
            a[x][y]=i;
            if (x==y&&y==8){
                flag=1;
                return;
            } else {
                if (y==8) backtrack(x+1, 0);
                else backtrack(x, y+1);
            }
            a[x][y]=0;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    for(int i=0; i<9; ++i) for(int j=0; j<9; ++j){
        std::cin >> a[i][j];
        if (a[i][j]){
            r[i][a[i][j]]=1;
            c[j][a[i][j]]=1;
            z[i%3+j%3][a[i][j]]=1;
        }
    }
    backtrack(0, 0);
    if (!flag){
        std::cout << "No";
        return 0;
    } 
    std::cout << "Yes\n";
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j) std::cout << a[i][j] << " \n"[j==8];
    }
}