#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char s[maxn];
int p, n;

int dfs(){
    int tmp = 0, res = 0;
    while(p < n){
        if(s[p] == '('){
            p++;
            tmp += dfs();
        }
        else if(s[p] == ')'){
            p++;
            res = max(res, tmp);
            break;
        }
        else if(s[p] == '|'){
            p++;
            res = max(res, tmp);
            tmp = 0;
        }
        else{
            p++;
            tmp++;
        }
    }
    res = max(res, tmp);
    return res;
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    p = 0;
    int ans = dfs();
    printf("%d\n", ans);
    return 0;
}
