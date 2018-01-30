#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int ar[maxn];
int s[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    s[0] = 0;
    int n = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", ar + i);
        if(ar[i] == 2){
            n++;
        }
        if(ar[i] != 1){
            ar[i] = 0;
        }
        s[i] = s[i-1] + ar[i];
    }
    long long ans = 0;
    for(int i = 1; i < N; i++){
        if(ar[i] == 1){
            ans += N - i + s[N] - s[i];
        }
        else{
            ans += s[N] - s[i];
        }
    }
    ans += 1LL * n * (n - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}
