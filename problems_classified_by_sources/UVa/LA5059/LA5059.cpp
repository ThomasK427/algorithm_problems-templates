#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL SG(LL x){
    if(x == 1){
        return 0;
    }
    else if(x % 2 == 0){
        return x / 2;
    }
    else{
        return SG(x / 2);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        LL nim = 0;
        for(int i = 0; i < N; i++){
            LL x;
            scanf("%lld", &x);
            nim ^= SG(x);
        }
        if(nim){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
