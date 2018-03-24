#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

int ar[maxn];
int n, ans = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    for(int S = 0; S < (1 << n); S++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(S & (1 << i)){
                sum += ar[i];
            }
        }
        if(sum == 40){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
