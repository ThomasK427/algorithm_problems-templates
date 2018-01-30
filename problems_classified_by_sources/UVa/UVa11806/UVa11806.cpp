#include <bits/stdc++.h>
using namespace std;
const int maxn = 550;
const int Q = 1000007;

int C[maxn][maxn];

int main()
{
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j - 1]) % Q;
        }
    }
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int sum = 0;
        for(int S = 0; S < 16; S++){
            int b = 0, r = n, c = m;
            if(S & 1){
                r--;
                b++;
            }
            if(S & 2){
                r--;
                b++;
            }
            if(S & 4){
                c--;
                b++;
            }
            if(S & 8){
                c--;
                b++;
            }
            if(b & 1){
                sum = (sum + Q - C[r * c][k]) % Q;
            }
            else{
                sum = (sum + C[r * c][k]) % Q;
            }
        }
        printf("Case %d: %d\n", ++kase, sum);
    }
    return 0;
}
