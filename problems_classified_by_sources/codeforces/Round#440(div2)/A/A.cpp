#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];
set<int> st;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m, x;
    scanf("%d%d", &n, &m);
    int a = INF, b = INF, c = INF;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a = min(a, x);
        st.insert(x);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        b = min(b, x);
        if(st.count(x)){
            c = min(c, x);
        }
    }
    if(a == b){
        printf("%d\n", a);
    }
    else if(c < INF){
        printf("%d\n", c);
    }
    else if(a < b){
        printf("%d%d\n", a, b);
    }
    else{
        printf("%d%d\n", b, a);
    }
    return 0;
}
