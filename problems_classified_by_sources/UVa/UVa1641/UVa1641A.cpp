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
        double ans = 0;
        for(int j = 0; j < w; j++){
            bool in = false;
            for(int i = 0; i < h; i++){
                if(g[i][j] != '.'){
                    ans += 0.5;
                    in = !in;
                }
                else{
                    if(in){
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
