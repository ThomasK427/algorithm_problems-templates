#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

LL y[maxn];

inline bool check(int u, int v)
{
    return (y[u] - y[1]) * (v - 1) == (y[v] - y[1]) * (u - 1);
}

inline bool check(int u, int v, int w)
{
    return (y[u] - y[w]) * (v - w) == (y[v] - y[w]) * (u - w);
}

inline bool check(int a, int b, int u, int v)
{
    return (y[a] - y[b]) * (u - v) == (y[u] - y[v]) * (a - b);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> y[i];
    }
    bool flag = true;
    if(n == 3){
        if(check(1, 2, 3)){
            flag = false;
        }
    }
    else{
        flag = false;
        for(int k = 2; k <= n; k++){
            vector<int> v;
            for(int i = 2; i <= n; i++){
                if(i != k){
                    if(!check(i, k)){
                        v.push_back(i);
                    }
                }
            }
            if(v.size() == 0){
                continue;
            }
            else if(v.size() == 1){
                flag = true;
                break;
            }
            else{
                bool ok = true;
                for(int i = 1; i < v.size(); i++){
                    if(!check(1, k, v[0], v[i])){
                        ok = false;
                    }
                }
                if(ok){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            bool ok = true;
            if(check(1, 2, 3)){
                ok = false;
            }
            else{
                for(int i = 4; i <= n; i++){
                    if(!check(2, 3, i)){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                flag = true;
            }
        }
    }
    if(flag){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
