#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

LL a[maxn];
vector<int> v[maxn * maxn];

inline int f(int i, int j)
{
    return i * 1007 + j;
}

unordered_map<LL, int> mp;

int main()
{
    //freopen("test.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", a + i);
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            LL x = a[i] + a[j];
            if(mp.find(x) == mp.end()){
                cnt++;
                mp[x] = cnt;
                v[cnt].push_back(f(i, j));
            }
            else{
                int idx = mp[x];
                v[idx].push_back(f(i, j));
            }
        }
    }
    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            LL x = -(a[i] + a[j]);
            if(mp.find(x) != mp.end()){
                int idx = mp[x];
                for(int k = 0; k < v[idx].size(); k++){
                    int p = v[idx][k] / 1007, q = v[idx][k] % 1007;
                    if((i != p) && (i != q) && (j != p) && (j != q)){
                        flag = true;
                        goto HERE;
                    }
                }
            }
        }
    }
    HERE:;
    if(flag){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
