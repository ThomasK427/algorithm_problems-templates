#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 200000 + 200;

char str[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, t;
    while(~scanf("%d%d", &n, &t)){
        scanf("%s", str);
        int p = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '.'){
                p = i;
                break;
            }
        }
        if(str[p+1] >= '5'){
            THERE:;
            str[p--] = '\0';
            while(str[p] == '9' && p >= 0){
                str[p--] = '0';
            }
            if(p == -1){
                printf("1");
                printf("%s\n", str);
            }
            else{
                str[p]++;
                printf("%s\n", str);
            }
        }
        else{
            int q = p;
            for(int i = p + 1; i < n; i++){
                if(str[i] >= '5'){
                    q = i;
                    break;
                }
            }
            if(q == p){
                goto HERE;
            }
            while(q > p){
                str[q--] = '\0';
                while(str[q] == '9' && q > p + 1){
                    str[q--] = '\0';
                }
                if(q == p + 1){
                    if(str[q] == '9'){
                        goto THERE;
                    }
                    else{
                        str[q]++;
                        if(t > 1 && str[q] >= '5'){
                            goto THERE;
                        }
                        else{
                            goto HERE;
                        }
                    }
                }
                str[q]++;
                t--;
                if(t <= 0 || str[q] < '5'){
                    goto HERE;
                }
            }
            if(q == p + 1){
                goto THERE;
            }
            HERE:;
            printf("%s\n", str);
        }
    }
    return 0;
}

