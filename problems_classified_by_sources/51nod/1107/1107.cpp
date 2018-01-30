#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int x, y;
    friend bool operator<(const Node& a, const Node& b){
        if(a.x != b.x){
            return a.x < b.x;
        }
        else{
            return a.y < b.y;
        }
    }
}E[maxn];

unordered_map<int, int> mp;
int ar[maxn];
int N, idx;
int bit[maxn];

inline int lowbit(int x){
    return x & (-x);
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x){
    while(x <= idx){
        bit[x]++;
        x += lowbit(x);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &E[i].x, &E[i].y);
        ar[i] = E[i].y;
    }
    sort(ar, ar + N);
    idx = 0;
    for(int i = 0; i < N; i++){
        if(!mp.count(ar[i])){
            mp[ar[i]] = ++idx;
        }
    }
    sort(E, E + N);
    for(int i = 0; i < N; i++){
        E[i].y = mp[E[i].y];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += sum(idx) - sum(E[i].y);
        add(E[i].y);
    }
    printf("%d\n", ans);
    return 0;
}
