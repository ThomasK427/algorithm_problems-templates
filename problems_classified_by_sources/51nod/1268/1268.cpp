#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;

int a[maxn];
set<int> st;
int N;

void dfs(int k, int s)
{
    if(k == N){
        st.insert(s);
    }
    else{
        dfs(k + 1, s);
        dfs(k + 1, s + a[k]);
    }
}

int main()
{
    int K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", a + i);
    }
    dfs(0, 0);
    if(st.find(K) == st.end()){
        puts("No");
    }
    else{
        puts("Yes");
    }
    return 0;
}
