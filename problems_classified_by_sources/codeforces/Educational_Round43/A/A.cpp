#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

char str[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    if(cnt0 == 0){
        puts("1");
    }
    else if(cnt1 == 0){
        puts("0");
    }
    else{
        putchar('1');
        for(int i = 0; i < cnt0; i++){
            putchar('0');
        }
        putchar('\n');
    }
    return 0;
}
