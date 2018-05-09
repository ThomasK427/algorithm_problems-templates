#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

char str[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    set<int> st;
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int l = strlen(str);
        int s = 0;
        for(int j = 0; j < l; j++){
            s |= (1 << (str[j] - 'a'));
        }
        st.insert(s);
    }
    printf("%d\n", int(st.size()));
    return 0;
}
