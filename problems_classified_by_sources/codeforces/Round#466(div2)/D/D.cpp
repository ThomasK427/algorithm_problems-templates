#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int a[maxn], amax[maxn], amin[maxn];
char bp[maxn];

inline bool check(int i, int x){
    char ch = x + '0';
    return bp[i - 1] == ch && bp[i - 2] == ch && bp[i - 3] == ch && bp[i - 4] == ch;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    for(int i = 4; i < n; i++){
        amax[i] = max(a[i], max(max(a[i - 1], a[i - 2]), max(a[i - 3], a[i - 4])));
        amin[i] = min(a[i], min(min(a[i - 1], a[i - 2]), min(a[i - 3], a[i - 4])));
    }
    scanf("%s", bp);
    int l = -1e9, r = 1e9;
    for(int i = 4; i < n; i++){
        if(bp[i] == '0'){
            if(check(i, 1)){
                r = min(r, amin[i] - 1);
            }
        }
        else{
            if(check(i, 0)){
                l = max(l, amax[i] + 1);
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}

