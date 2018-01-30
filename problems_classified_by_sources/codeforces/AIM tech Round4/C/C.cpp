#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

struct Node{
    int val, idx, rk;
}E[maxn];

bool mp[maxn];

bool cmp1(const Node& e1, const Node& e2){
    return e1.val < e2.val;
}

bool cmp2(const Node& e1, const Node& e2){
    return e1.idx < e2.idx;
}

vector<vector<int> > ans;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    memset(mp, false, sizeof(mp));
    for(int i = 1; i <= n; i++){
        scanf("%d", &E[i].val);
        E[i].idx = i;
    }
    sort(E + 1, E + n + 1, cmp1);
    for(int i = 1; i <= n; i++){
        E[i].rk = i;
    }
    sort(E + 1, E + n + 1, cmp2);
    for(int i = 1; i <= n; i++){
        if(!mp[i]){
            vector<int> v;
            int x = i;
            do{
                v.push_back(x);
                mp[x] = true;
                x = E[x].rk;
            }while(x != i);
            ans.push_back(v);
        }
    }
    printf("%d\n", int(ans.size()));
    for(int i = 0; i < ans.size(); i++){
        printf("%d", int(ans[i].size()));
        sort(ans[i].begin(), ans[i].end());
        for(int j = 0; j < ans[i].size(); j++){
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
