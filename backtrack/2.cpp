#include<iostream>
#include<vector>

int n;
bool flag;
std::vector<bool> c, x1, x2;
std::vector<int> res;

void backtrack(int id){
    if (flag) return;
    for(int i=0; i<n; ++i) if (!c[i]&&!x1[id-i+7]&&!x2[id+i]){
        c[i]=1;
        x1[id-i+7]=1;
        x2[id+i]=1;
        res.push_back(i);
        if (id==n-1){
            for(int j=0; j<id; ++j) std::cout << i+1 <<  " " << res[j]+1 << '\n';
            flag=1;
        }
        else backtrack(id+1);
        c[i]=0;
        x1[id-i+7]=0;
        x2[id+i]=0;
        res.pop_back();
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    std::cin >> n;
    c.resize(n);
    x1.resize(n<<1);
    x2.resize(n<<1);
    backtrack(0);
}