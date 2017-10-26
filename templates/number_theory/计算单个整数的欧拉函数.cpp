#include <bits/stdc++.h>
using namespace std;

int phi(int n){
    int x = n, ans = n;
    for(int i = 2; i <= x && i * i <= n; i++){
        if(x % i == 0){
            ans = ans / i * (i - 1);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x > 1){
        ans = ans / x * (x - 1);
    }
    return ans;
}

int main()  //51nod1136
{
    int N;
    scanf("%d", &N);
    printf("%d\n", phi(N));
    return 0;
}
