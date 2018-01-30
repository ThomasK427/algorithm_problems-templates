#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x, nim = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        nim ^= x;
    }
    if(nim){
        puts("A");
    }
    else{
        puts("B");
    }
    return 0;
}
