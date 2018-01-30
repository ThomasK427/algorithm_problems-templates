#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 400005;

int st[maxn], ed[maxn];
int br[maxn * 2];
vector<int> v;
map<int, int> mp;

int main()
{
    freopen("test.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        v.clear();
        mp.clear();
        int n, a, b;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", st + i, ed + i);
            v.push_back(st[i]);
            v.push_back(ed[i]);
        }
        sort(v.begin(), v.end());
        int ans = unique(v.begin(), v.end()) - v.begin();
        for(int i = 0; i < ans; i++){
            mp[v[i]] = i;
        }
        for(int i = 0; i < n; i++){
            a = mp[st[i]];
            b = mp[ed[i]];
            br[a]++;
            br[b]--;
        }
        for(int i = 1; i < maxn * 2; i++){
            br[i] += br[i-1];
        }
        int mx = 0;
        for(int i = 0; i < maxn * 2; i++){
            mx = max(mx, br[i]);
        }
        cout << mx << endl;
    }
    return 0;
}
