#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int C[maxn], W[maxn], P[maxn];
int N;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d%d", C + i, W + i, P + i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++, ans++){
        bool flag = false;
        int p = P[i], x = W[i];
        while(p >= 0){
            W[p] += x;
            if(W[p] > C[p]){
                flag = true;
                break;
            }
            p = P[p];
        }
        if(flag){
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
