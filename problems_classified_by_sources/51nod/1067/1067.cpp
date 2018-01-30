#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        N %= 7;
        if(N == 0 || N == 2){
            puts("B");
        }
        else{
            puts("A");
        }
    }
    return 0;
}
