#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int ar[maxn], t[maxn], L[maxn], R[maxn];
int n, q, m;

int main()
{
    scanf("%d%d%d", &n, &q, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
    }
    for(int i = 1; i <= q; i++){
        scanf("%d%d%d", t + i, L + i, R + i);
    }
    for(int i = 1; i <= m; i++){
        int b;
        scanf("%d", &b);
        for(int j = q; j >= 1; j--){
            if(t[j] == 1){
                if(L[j] < b && b <= R[j]){
                    b--;
                }
                else if(L[j] == b){
                    b = R[j];
                }
            }
            else{
                if(L[j] <= b && b <= R[j]){
                    b = L[j] + R[j] - b;
                }
            }
        }
        printf("%d%c", ar[b], i == m ? '\n' : ' ');
    }
    return 0;
}
