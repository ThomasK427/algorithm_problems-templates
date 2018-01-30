#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

bool valid[maxn];
int v2[maxn];
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
            if(i % ans[j] == 0)break;
        }
    }
}

bool check(int x)
{
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return valid[sum];
}

int main()
{
    getPrime();
    memset(v2, 0, sizeof(v2));
    for(int i = 1; i <= tot; i++){
        int x = ans[i];
        if(check(x)){
            v2[x] = 1;
        }
    }
    for(int i = 1; i < maxn; i++){
        v2[i] += v2[i-1];
    }
    int N, a, b;
    scanf("%d", &N);
    while(N--){
        scanf("%d%d", &a, &b);
        printf("%d\n", v2[b] - v2[a-1]);
    }
    return 0;
}
