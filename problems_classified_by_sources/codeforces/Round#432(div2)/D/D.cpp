#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 500005;
const int maxp = 1000000;

bool valid[maxp];
int prime[maxp];
int tot;

void getPrime(){
    tot = 0;
    for(int i = 2; i < maxp; i++){
        valid[i] = true;
    }
    for(int i = 2; i < maxp; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] < maxp; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

map<int, int> mp;
int ar[maxn];

void split(int x){
    for(int i = 1; prime[i] <= x / prime[i]; i++){
        if(x % prime[i] == 0){
            mp[prime[i]]++;
            while(x % prime[i] == 0){
                x /= prime[i];
            }
        }
    }
    if(x > 1){
        mp[x]++;
    }
}

inline int Find(int x, int y){
    return (y / x + 1) * x;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    getPrime();
    int n;
    LL x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
        split(ar[i]);
    }
    vector<P> v;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        v.push_back(P(it->second, it->first));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int mx = min(100, int(v.size()));
    LL ans = inf;
    set<int> st;
    if(mx == 0){
        ans = n * min(x, y);
    }
    else{
        for(int i = 0; i < mx; i++){
            st.insert(v[i].second);
        }
        for(int i = 1; i <= 200; i++){
            st.insert(prime[i]);
        }
    }
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        int u = *it;
        LL res = 0;
        for(int i = 1; i <= n; i++){
            if(ar[i] % u != 0){
                res += min(x, y * (Find(u, ar[i]) - ar[i]));
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
