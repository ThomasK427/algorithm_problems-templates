#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000000;

int ans[maxn + 10];

int main()
{
    for(int c = 1; c <= maxn / 2; c++){
        for(int a = 2 * c; a <= maxn; a += c){
            int b = a - c;
            if(c == (a ^ b)){
                ans[a]++;
            }
        }
    }
    for(int i = 1; i <= maxn; i++){
        ans[i] += ans[i-1];
    }
    int T, n;
    int kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("Case %d: %d\n", ++kase, ans[n]);
    }
    return 0;
}
