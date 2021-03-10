#include<iostream>
#include<vector>

using std::vector;
using std::pair;

const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1},
          dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n;
bool flag;
vector<vector<bool>> c;
vector<pair<int, int>> res;

bool inside(int x, int y){
    return 0<=x&&x<n && 0<=y&&y<n;
}

void backtrack(int x, int y){
    if (res.size()==n*n) flag=1;
    if (flag) return;
    for(int i=0; i<8; ++i){
        int nx(x+dx[i]), ny(y+dy[i]);
        if (inside(nx, ny)){
            if (!c[nx][ny]){
                c[nx][ny]=1;
                res.push_back({nx, ny});
                if (res.size()==n*n){
                    flag=1;
                    for(int j=0; j<res.size(); ++j) std::cout << res[j].first+1 << " " << res[j].second+1 << '\n';
                    return;
                } else {
                    backtrack(nx, ny);
                    c[nx][ny]=0;
                    res.pop_back();
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);   

    std::cin >> n;
    c = vector<vector<bool>>(n, vector<bool>(n));
    c[0][0]=1;
    res.push_back({0, 0});
    backtrack(0, 0);
}