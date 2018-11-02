#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

vector<int> g[maxn];

bool bfs(int s, int t){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i = 0; i < g[p].size(); i++){
            if(g[p][i] == t){
                return true;
            }
            q.push(g[p][i]);
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mp;
    int id = 0;
    for(int i = 0; i < n; i++){
        string a, b, s;
        cin >> a >> s >> s >> s >> b;
        if(!mp.count(a)){
            mp[a] = ++id;
        }
        if(!mp.count(b)){
            mp[b] = ++id;
        }
        g[mp[a]].push_back(mp[b]);
    }
    for(int i = 0; i < m; i++){
        string a, b, s;
        cin >> a >> s >> s >> s >> b;
        if(mp[a] == 0 || mp[b] == 0){
            puts("Pants on Fire");
        }
        else if(bfs(mp[a], mp[b])){
            puts("Fact");
        }else if(bfs(mp[b], mp[a])){
            puts("Alternative Fact");
        }else{
            puts("Pants on Fire");
        }
    }
    return 0;
}
