#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

char g[maxn][maxn];

void draw(int a, int b, int c){
    int w = 2 * a + 1 + 2 * b, h = 2 * c + 1 + 2 * b;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            g[i][j] = '.';
        }
        g[i][w] = '\0';
        for(int i = 2 * b; i < h; i++){
            for(int j = 0; j < 2 * a + 1; j++){
                if(i % 2 == 0){
                    if(j % 2 == 0){
                        g[i][j] = '+';
                    }else{
                        g[i][j] = '-';
                    }
                }else{
                    if(j % 2 == 0){
                        g[i][j] = '|';
                    }
                }
            }
        }
        for(int i = 0; i < 2 * b; i++){
            int bg = 2 * b - i, ed = bg + 2 * a;
            for(int j = bg; j <= ed; j++){
                if(i % 2 == 0){
                    if(j % 2 == 0){
                        g[i][j] = '+';
                    }else{
                        g[i][j] = '-';
                    }
                }else{
                    if(j % 2 == 1){
                        g[i][j] = '/';
                    }
                }
            }
        }
        for(int j = 2 * a + 1; j < w; j++){
            int bg = 2 * b - (j - 2 * a), ed = bg + 2 * c;
            for(int i = bg; i <= ed; i++){
                if(j % 2 == 1){
                    if(i % 2 == 1){
                        g[i][j] = '/';
                    }
                }else{
                    if(i % 2 == 0){
                        g[i][j] = '+';
                    }else{
                        g[i][j] = '|';
                    }
                }
            }
        }
        puts(g[i]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        draw(a, b, c);
    }
    return 0;
}
