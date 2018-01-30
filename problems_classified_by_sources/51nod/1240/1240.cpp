#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int m = int(sqrt(n)) + 1;
    bool flag = false;
    int k = 0;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            n /= i;
            if(n % i == 0){
                flag = true;
                break;
            }
            k++;
        }
        if(i >= m && n > 1){
            k++;
            break;
        }
    }
    if(flag){
        puts("0");
    }
    else if(k & 1){
        puts("-1");
    }
    else{
        puts("1");
    }
    return 0;
}
