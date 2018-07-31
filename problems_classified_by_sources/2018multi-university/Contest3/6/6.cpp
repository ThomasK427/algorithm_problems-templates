#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int xor_sum = 0;
        for(int i = 0; i < n; i++){
            int w;
            scanf("%d", &w);
            xor_sum ^= w;
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            scanf("%d%d", &u, &v);
        }
        if(xor_sum > 0){
            puts("Q");
        }else{
            puts("D");
        }
    }
    return 0;
}
