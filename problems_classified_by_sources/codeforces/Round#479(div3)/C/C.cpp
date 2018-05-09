#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int ar[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    sort(ar, ar + n);
    if(k == 0){
        if(ar[0] > 1){
            puts("1");
        }
        else{
            puts("-1");
        }
    }
    else{
        if(k < n && ar[k - 1] == ar[k]){
            puts("-1");
        }
        else{
            printf("%d\n", ar[k - 1]);
        }
    }
    return 0;
}
