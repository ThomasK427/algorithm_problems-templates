#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int ar[maxn];

int main()
{
    ar[0] = 0;
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", ar + i);
    }
    int ans = 5 * N;
    for(int i = 1; i <= N; i++){
        if(ar[i] > ar[i - 1]){
            ans += (ar[i] - ar[i - 1]) * 6;
        }
        else{
            ans += (ar[i - 1] - ar[i]) * 4;
        }
    }
    printf("%d\n", ans);
    return 0;
}
