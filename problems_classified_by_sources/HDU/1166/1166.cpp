#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int bit[maxn];
int n;

int lowbit(int x){
    return x & (-x);
}

int sum(int id){
    int res = 0;
    while(id > 0){
        res += bit[id];
        id -= lowbit(id);
    }
    return res;
}

void add(int id, int x){
    while(id <= n){
        bit[id] += x;
        id += lowbit(id);
    }
}

int main()
{
    int T, kase = 0;;
    scanf("%d", &T);
    while(T--){
        printf("Case %d:\n", ++kase);
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            add(i, x);
        }
        char str[10];
        int i, j;
        while(~scanf("%s", str)){
            if(strcmp(str, "Add") == 0){
                scanf("%d%d", &i, &j);
                add(i, j);
            }
            else if(strcmp(str, "Sub") == 0){
                scanf("%d%d", &i, &j);
                add(i, -j);
            }
            else if(strcmp(str, "Query") == 0){
                scanf("%d%d", &i, &j);
                printf("%d\n", sum(j) - sum(i - 1));
            }
            else{
                break;
            }
        }
    }
    return 0;
}
