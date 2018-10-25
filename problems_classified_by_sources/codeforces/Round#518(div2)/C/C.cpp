#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

vector<int> a[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set<int> st;
    int i = 1;
    for(; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(i);
        a[y].push_back(i);
        st.insert(x);
        st.insert(y);
    }
    i = 2 * m;
    for(int j = 1; j <= n; j++){
        if(st.count(j) == 0){
            a[j].push_back(++i);
        }
    }
    while(i < 5000){
        a[1].push_back(++i);
    }
    for(int i = 1; i <= n; i++){
        printf("%d\n", a[i].size());
        for(int j = 0; j < a[i].size(); j++){
            printf("%d %d\n", i, a[i][j]);
        }
    }
    return 0;
}
