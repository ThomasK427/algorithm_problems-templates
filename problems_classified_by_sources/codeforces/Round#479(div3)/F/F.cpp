#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int ar[maxn], pre[maxn], dp[maxn], ans[maxn];
unordered_map<int, int> mp;

int Scan(){   //  输入外挂
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-'){
        flag = 1;
    }
    else if(ch >= '0' && ch <= '9'){
        res = ch - '0';
    }
    while((ch = getchar()) >= '0' && ch <= '9'){
        res = res * 10 + (ch - '0');
    }
    return flag ? -res : res;
}

void Out(int a){   //  输出外挂
    if(a < 0){
        putchar('-');
        a = -a;
    }
    if(a >= 10){
       Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int main()
{
    int n = Scan();
    for(int i = 1; i <= n; i++){
        ar[i] = Scan();
    }
    for(int i = 1; i <= n; i++){
        pre[i] = mp[ar[i] - 1];
        mp[ar[i]] = i;
    }
    int p = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[pre[i]] + 1;
        if(dp[i] > dp[p]){
            p = i;
        }
    }
    int q = 0;
    while(p){
        ans[++q] = p;
        p = pre[p];
    }
    Out(q);
    putchar('\n');
    for(int i = q; i >= 1; i--){
        Out(ans[i]);
        putchar(i == 1 ? '\n' : ' ');
    }
    return 0;
}
