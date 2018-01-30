#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

struct Node{
    int a, b, c;
    Node(){}
    Node(int x, int y, int z):a(x), b(y), c(z){}
}E[maxn];

vector<int> v[maxn];
int dp[maxn];

int deep(int x){
    int& ans = dp[x];
    if(ans > 0){
        return ans;
    }
    ans = E[x].c;
    for(int i = 0; i < v[x].size(); i++){
        ans = max(ans, E[x].c + deep(v[x][i]));
    }
    return ans;
}

int main()
{
    int n, kase = 0;
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            E[i * 3] = Node(x, y, z);
            E[i * 3 + 1] = Node(x, z, y);
            E[i * 3 + 2] = Node(y, z, x);
            v[i * 3].clear();
            v[i * 3 + 1].clear();
            v[i * 3 + 2].clear();
        }
        n *= 3;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if((E[i].a < E[j].a && E[i].b < E[j].b) || (E[i].a < E[j].b && E[i].b < E[j].a)){
                    v[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, deep(i));
        }
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }
    return 0;
}
