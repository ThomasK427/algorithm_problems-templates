#include <stdio.h>
using namespace std;
const int maxn = 5000005;

bool valid[maxn];
int prime[maxn];
int s[maxn];
int tot;

void getPrime()
{
    for(int i = 2; i < maxn; i++){
        valid[i] = true;
    }
    tot = 0;
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] < maxn; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0)break;
        }
    }
}

int main()
{
    getPrime();
    for(int i = 2; i < maxn; i++){
        s[i] = s[i - 1];
        int x = i;
        for(int j = 1; prime[j] * prime[j] <= x; j++){
            while(x % prime[j] == 0){
                s[i]++;
                x /= prime[j];
            }
        }
        if(x > 1){
            s[i]++;
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", s[a] - s[b]);
    }
    return 0;
}
