#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int ar[maxn];

bool isPrime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int gent(){
    int res = 0;
    for(int i = 0; i < 8; i++){
        res = res * 10 + ar[i];
    }
    return res;
}

int main()
{
    for(int i = 0; i < 8; i++){
        ar[i] = i;
    }
    int ans = 0;
    do{
        if(ar[0]){
            if(isPrime(gent())){
                ans++;
            }
        }
    }while(next_permutation(ar, ar + 8));
    printf("%d\n", ans);
    return 0;
}
