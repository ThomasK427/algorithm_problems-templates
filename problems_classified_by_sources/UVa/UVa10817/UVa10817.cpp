#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 125;

int S, M, N;
int c[maxn];
int st[maxn];
int dp[521][521];
char str[1000];

int main()
{
    //freopen("test.txt", "r", stdin);
    while((cin >> S >> M >> N) && S){
        memset(st, 0, sizeof(st));
        gets(str);
        for(int i = 0; i < M + N; i++){
            gets(str);
            stringstream ss(str);
            ss >> c[i];
            int x;
            while(ss >> x){
                st[i] |= (1 << (x - 1));
            }
        }
        int sum = 0, S1 = 0, S2 = 0;
        for(int i = 0; i < M; i++){
            sum += c[i];
            S2 |= (S1 & st[i]);
            S1 |= st[i];
        }
        memset(dp, INF, sizeof(dp));
        dp[S1][S2] = sum;
        int mx = (1 << S) - 1;
        for(int i = M; i < M + N; i++){
            for(int s1 = mx; s1 >= 0; s1--){
                for(int s2 = s1; s2 >= 0; s2--){
                    if((dp[s1][s2] >= INF) || (s1 != (s1 ^ s2) + s2)){
                        continue;
                    }
                    int nextS2 = (st[i] & s1) | s2, nextS1 = st[i] | s1;
                    dp[nextS1][nextS2] = min(dp[nextS1][nextS2], dp[s1][s2] + c[i]);
                }
            }
        }
        printf("%d\n", dp[mx][mx]);
    }
    return 0;
}
