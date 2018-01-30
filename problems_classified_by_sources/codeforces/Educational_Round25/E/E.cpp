#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int ans[maxn];
int degree[maxn];
vector<int> v[maxn];
priority_queue<int> pq;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        memset(ans, 0, sizeof(ans));
        memset(degree, 0, sizeof(degree));
        for(int i = 1; i <= n; i++){
            v[i].clear();
        }
        while(!pq.empty()){
            pq.pop();
        }
        int a, b;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            degree[a]++;
            v[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(degree[i] == 0){
                pq.push(i);
            }
        }
        int cnt = n;
        while(!pq.empty()){
            int idx = pq.top();
            pq.pop();
            ans[idx] = cnt--;
            for(int i = 0; i < v[idx].size(); i++){
                int p = v[idx][i];
                degree[p]--;
                if(degree[p] == 0){
                    pq.push(p);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
