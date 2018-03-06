#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    int n, x;
    scanf("%d", &n);
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x > 0){
            st.insert(x);
        }
    }
    printf("%d\n", int(st.size()));
    return 0;
}
