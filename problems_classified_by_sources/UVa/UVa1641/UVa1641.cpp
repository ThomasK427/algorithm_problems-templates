#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char g[maxn][maxn];

int main()
{
    int h, w;
    while(~scanf("%d%d", &h, &w)){
        for(int i = 0; i < h; i++){
            scanf("%s", g[i]);
        }
        int ans = 0;
        for(int j = 0; j < w; j++){
            bool in = false;
            for(int i = 0; i < h; i++){
                if(g[i][j] == '.'){
                    if(in){
                        ans += 2;
                    }
                }
                else{
                    ans += 1;
                    in = !in;
                }
            }
        }
        if(ans % 2 == 0){
            printf("%d\n", ans / 2);
        }
        else{
            printf("%d.5\n", ans / 2);
        }
    }
    return 0;
}
