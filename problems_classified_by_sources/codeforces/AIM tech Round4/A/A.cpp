#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

char str[maxn];
set<char> st;

int main()
{
    //freopen("test.txt", "r", stdin);
    int k;
    scanf("%s%d", str, &k);
    int n = strlen(str);
    if(n < k){
        puts("impossible");
    }
    else{
        for(int i = 0; i < n; i++){
            st.insert(str[i]);
        }
        printf("%d\n", max(0, k - int(st.size())));
    }
    return 0;
}

