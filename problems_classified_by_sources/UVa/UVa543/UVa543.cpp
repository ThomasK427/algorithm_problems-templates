#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;

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
    while(~scanf("%d", &n) && n){
        for(int i = 1; i <= tot / 2; i++){
            int x = ans[i], y = n - x;
            if(valid[y]){
                printf("%d = %d + %d\n", n, x, y);
                break;
            }
        }
    }
    return 0;
}


