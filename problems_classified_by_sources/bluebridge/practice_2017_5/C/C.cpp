#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int ar[maxn];
int g[maxn][maxn];

int main()
{
    for(int i = 1; i <= 9; i++){
        ar[i] = i;
    }
    int ans = 0;
    do{
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                g[i][j] = ar[(i - 1) * 3 + j];
            }
        }
        set<int> stx, sty;
        for(int i = 1; i <= 3; i++){
            int sum = 0;
            for(int j = 1; j <= 3; j++){
                sum += g[i][j];
            }
            stx.insert(sum);
        }
        for(int j = 1; j <= 3; j++){
            int sum = 0;
            for(int i = 1; i <= 3; i++){
                sum += g[i][j];
            }
            sty.insert(sum);
        }
        if(stx.size() == 1 && sty.size() == 1){
            ans++;
        }
    }while(next_permutation(ar + 1, ar + 10));
    printf("%d\n", ans);
    return 0;
}
