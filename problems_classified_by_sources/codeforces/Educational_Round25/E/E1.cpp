#include<bits/stdc++.h>
using namespace std;
const long long MX = (1<<20);
int n , deg[MX] , ans[MX] , m;
vector < int > v[MX];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int a , b;
        scanf("%d %d",&a,&b);
        v[b].push_back(a);
        deg[a]++;
    }
    priority_queue < int > Q;
    for(int j = 1 ; j <= n ; j++) if(deg[j] == 0) Q.push(j);
    int timer = n;
    while(!Q.empty()){
        int x = Q.top(); Q.pop();
        ans[x] = timer--;
        for(int i = 0; i < v[x].size(); i++){
            int nxt = v[x][i];
            --deg[nxt];
            if(deg[nxt] == 0)
                Q.push(nxt);
        }
    }
    for(int j = 1 ; j <= n ; j++) printf("%d ",ans[j]);
}
