#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;

int post[maxn], in[maxn];
queue<int> que[maxn];
int N;

int Find(int x){
    for(int i = 1; i <= N; i++){
        if(in[i] == x){
            return i;
        }
    }
}

void solve(int s1, int t1, int s2, int t2, int k){
    que[k].push(post[t1]);
    int p = Find(post[t1]);
    int nl = p - s2, nr = t2 - p;
    if(nl > 0){
        solve(s1, s1 + nl - 1, s2, p - 1, k + 1);
    }
    if(nr > 0){
        solve(s1 + nl, t1 - 1, p + 1, t2, k + 1);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", post + i);
    }
    for(int i = 1; i <= N; i++){
        scanf("%d", in + i);
    }
    solve(1, N, 1, N, 1);
    int c = 0;
    for(int i = 1; !que[i].empty(); i++){
        while(!que[i].empty()){
            printf("%d%c", que[i].front(), ++c == N ? '\n' : ' ');
            que[i].pop();
        }
    }
    return 0;
}
