#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &K);
        if(N % (K + 1) == 0){
            puts("B");
        }
        else{
            puts("A");
        }
    }
    return 0;
}
