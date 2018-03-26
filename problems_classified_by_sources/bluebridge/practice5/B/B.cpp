#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;

int g[maxn][maxn] = { {1, 4, 2, 5}, {2, 1, 2, 1}, {3, 1, 3, 2}, {2, 5, 3, 4} };
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool used[maxn], uu[maxn];

int hs(int x, int y){
    return x + y * 4;
}

int rhs(int S){
    int x = S % 4, y = S / 4;
    return g[x][y];
}

bool ext(int S, int k){
    return S & (1 << k);
}

bool check(int x, int y){
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void print(int S){
    for(int i = 0; i < 16; i++){
        printf("%d ", S % 2);
        S /= 2;
    }
    putchar('\n');
}

int ans = 0;
vector<int> v;

void dfs(int S, int k, int sum){
    bool flag = false;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            if(i != j && ext(S, i) && ext(S, j) && rhs(i) == rhs(j)){
                flag = true;
                int T = S;
                int s = k * rhs(i);
                int x = i % 4, y = i / 4;
                for(int r = 0; r < 16; r++){
                    uu[r] = used[r];
                }
                for(int r = 0; r < 4; r++){
                    int xx = x + d[r][0], yy = y + d[r][1];
                    if(check(xx, yy) && !used[hs(xx, yy)]){
                        T |= (1 << hs(xx, yy));
                        used[hs(xx, yy)] = true;
                    }
                }
                x = j % 4;
                y = j / 4;
                for(int r = 0; r < 4; r++){
                    int xx = x + d[r][0], yy = y + d[r][1];
                    if(check(xx, yy) && !used[hs(xx, yy)]){
                        T |= (1 << hs(xx, yy));
                        used[hs(xx, yy)] = true;
                    }
                }
                T ^= (1 << i);
                T ^= (1 << j);
                dfs(T, k + 1, sum + s);
                for(int r = 0; r < 16; r++){
                    used[r] = uu[r];
                }
            }
        }
    }
    if(!flag){
        v.push_back(sum);
        ans = max(ans, sum);
    }
}

int main()
{
    int S = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == 0 || i == 3 || j == 0 || j == 3){
                used[hs(i, j)] = true;
                S |= (1 << hs(i, j));
            }
        }
    }
    ans = 0;
    dfs(S, 1, 0);
    printf("%d\n", int(v.size()));
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << v[0] << endl;
    return 0;
}
