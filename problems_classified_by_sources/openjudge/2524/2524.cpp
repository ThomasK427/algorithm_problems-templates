#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int par[maxn];

int Find(int x){
    if(x == par[x]){
        return x;
    }
    else{
        return par[x] = Find(par[x]);
    }
}

void Unite(int x, int y){
    int a = Find(x), b = Find(y);
    par[a] = b;
}

int main()
{
    int n, m, kase = 0;
    while(~scanf("%d%d", &n, &m) && (n || m)){
        for(int i = 1; i <= n; i++){
            par[i] = i;
        }
        for(int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            Unite(a, b);
        }
        set<int> st;
        for(int i = 1; i <= n; i++){
            st.insert(Find(i));
        }
        printf("Case %d: %d\n", ++kase, int(st.size()));
    }
    return 0;
}
