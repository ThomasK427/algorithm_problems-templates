#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;

int g[maxn][maxn] = { {1, 4, 2, 5}, {2, 1, 2, 1}, {3, 1, 3, 2}, {2, 5, 3, 4} };
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int hs(int x, int y){
    return x + y * 4;
}

int rhs(int S){
    int x = S % 4, y = S / 4;
    return g[x][y];
}

bool check(int x, int y){
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int ans = 0;

void dfs(int k, int sum, vector<bool>& open, vector<bool> closed){
    ans = max(ans, sum);
    for(int i = 0; i < 16; i++){
        for(int j = i + 1; j < 16; j++){
            if(open[i] && open[j] && rhs(i) == rhs(j)){
                vector<bool> c_open = open, c_closed = closed;
                int t = k * rhs(i);
                int x = i % 4, y = i / 4;
                for(int r = 0; r < 4; r++){
                    int xx = x + d[r][0], yy = y + d[r][1];
                    if(check(xx, yy) && !open[hs(xx, yy)] && !closed[hs(xx, yy)]){
                        c_open[hs(xx, yy)] = true;
                    }
                }
                x = j % 4;
                y = j / 4;
                for(int r = 0; r < 4; r++){
                    int xx = x + d[r][0], yy = y + d[r][1];
                    if(check(xx, yy) && !open[hs(xx, yy)] && !closed[hs(xx, yy)]){
                        c_open[hs(xx, yy)] = true;
                    }
                }
                c_open[i] = false;
                c_closed[i] = true;
                c_open[j] = false;
                c_closed[j] = true;
                dfs(k + 1, sum + t, c_open, c_closed);
            }
        }
    }
}

int main()
{
    vector<bool> open, closed;
    for(int i = 0; i < 16; i++){
        open.push_back(false);
        closed.push_back(false);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == 0 || i == 3 || j == 0 || j == 3){
                open[hs(i, j)] = true;
            }
        }
    }
    dfs(1, 0, open, closed);
    printf("%d\n", ans);
    return 0;
}
