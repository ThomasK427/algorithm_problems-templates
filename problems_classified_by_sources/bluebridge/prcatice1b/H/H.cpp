#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 100000;
const int maxn = 1005;

char s[maxn], t[maxn];
int d[maxn][maxn];

int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int k;
    scanf("%d", &k);
    memset(d, INF, sizeof(d));
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j){
                d[i][j] = 0;
            }
            else{
                d[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < k; i++){
        char a, b;
        getchar();
        scanf("%c %c", &a, &b);
        //坑点: a和b可能相等
        if(a != b){
            d[a - 'a'][b - 'a'] = 1;
        }
    }
    for(int k = 0; k < 26; k++){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0, n = strlen(s);
    for(int i = 0; i < n; i++){
        if(d[s[i] - 'a'][t[i] - 'a'] == INF){
            ans = -1;
            break;
        }
        else{
            ans += d[s[i] - 'a'][t[i] - 'a'];
        }
    }
    printf("%d\n", ans);
    return 0;
}

