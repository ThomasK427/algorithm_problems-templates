#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int sg[maxn];
int s[maxn];
int d[10] = {1, 3, 7, 9};

int main()
{
    memset(sg, 0, sizeof(sg));
    for(int i = 1; i <= 1000; i++){
        memset(s, 0, sizeof(s));
        for(int j = 0; j < 4 && d[j] <= i; j++){
            s[sg[i - d[j]]] = 1;
        }
        for(int j = 0; ; j++){
            if(!s[j]){
                sg[i] = j;
                break;
            }
        }
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(sg[n] ^ sg[m] ^ sg[k]) printf("win");
    else printf("lose");
    return 0;
}
