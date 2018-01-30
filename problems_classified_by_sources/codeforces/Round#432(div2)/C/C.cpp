#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

struct Node{
    int a, b, c, d, e;
}E[maxn];

inline bool check(const Node& A, const Node& B, const Node& C){
    return (B.a - A.a) * (C.a - A.a) + (B.b - A.b) * (C.b - A.b) +
    (B.c - A.c) * (C.c - A.c) + (B.d - A.d) * (C.d - A.d) + (B.e - A.e) * (C.e - A.e) <= 0;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    vector<int> ans;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d%d%d", &E[i].a, &E[i].b, &E[i].c, &E[i].d, &E[i].e);
    }
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 1; j <= n; j++){
            if(j == i){
                continue;
            }
            for(int k = j + 1; k <= n; k++){
                if(k == i){
                    continue;
                }
                if(!check(E[i], E[j], E[k])){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            ans.push_back(i);
        }
    }
    printf("%d\n", int(ans.size()));
    for(int i = 0; i < ans.size(); i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}
