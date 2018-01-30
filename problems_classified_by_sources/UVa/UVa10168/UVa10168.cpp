#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000005;

bool valid[maxn];
int ans[maxn];
int tot = 0;

void getPrime()
{
    for(int i = 0; i < maxn; i++){
        valid[i] = true;
    }
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            tot++;
            ans[tot] = i;
        }
        for(int j = 1; (j <= tot) && (i * ans[j] < maxn); j++){
            valid[i * ans[j]] = false;
            if(i % ans[j] == 0){
                break;
            }
        }
    }
}

int main()
{
    getPrime();
    int n;
    while(~scanf("%d", &n)){
        if(n < 8){
            puts("Impossible.");
            continue;
        }
        if(n == 8){
            puts("2 2 2 2");
            continue;
        }
        else if(n == 9){
            puts("2 2 2 3");
            continue;
        }
        else if(n == 10){
            puts("2 2 3 3");
            continue;
        }
        else if(n == 11){
            puts("2 3 3 3");
            continue;
        }
        else if(n == 12){
            puts("3 3 3 3");
            continue;
        }
        if(n & 1){
            printf("2 3 ");
            n -= 5;
        }
        else{
            printf("2 2 ");
            n -= 4;
        }
        for(int i = 1; i <= tot / 2; i++){
            int x = ans[i], y = n - x;
            if(valid[y]){
                printf("%d %d\n", x, y);
                break;
            }
        }
    }
    return 0;
}


