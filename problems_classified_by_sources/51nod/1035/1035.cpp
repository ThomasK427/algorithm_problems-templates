#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int qpow(int n, int Q){
    int base = 10, res = 1;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        n >>= 1;
        base = base * base % Q;
    }
    return res;
}

int ans[maxn];

int main()
{
    for(int k = 1; k <= 1000; k++){
        int x = k;
        while(x % 2 == 0){
            x /= 2;
        }
        while(x % 5 == 0){
            x /= 5;
        }
        if(x == 1){
            ans[k] = 1;
        }
        else{
            for(int i = 1; ; i++){
                if(qpow(i, x) == 1){
                    ans[k] = i;
                    break;
                }
            }
        }
    }
    int n;
    scanf("%d", &n);
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, ans[i]);
    }
    for(int i = n; i >= 1; i--){
        if(res == ans[i]){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
