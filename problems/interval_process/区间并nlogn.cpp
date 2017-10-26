#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

struct Node{
    LL a, b;
}E[maxn];

int buf[maxn];
map<LL, int> mp1;
map<int, LL> mp2;
set<LL> st;
vector<LL> v;
int idx;

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld", &E[i].a, &E[i].b);
        if(!st.count(E[i].a)){
            v.push_back(E[i].a);
            st.insert(E[i].a);
        }
        if(!st.count(E[i].b)){
            v.push_back(E[i].b);
            st.insert(E[i].b);
        }
    }
    sort(v.begin(), v.end());
    idx = 0;
    mp1[v[0]] = ++idx;
    mp2[idx] = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i - 1] + 1){
            mp1[v[i]] = ++idx;
            mp2[idx] = v[i];
        }
        else{
            ++idx;
            mp1[v[i]] = ++idx;
            mp2[idx] = v[i];
        }
    }
    for(int i = 0; i < N; i++){
        buf[mp1[E[i].a]]++;
        buf[mp1[E[i].b] + 1]--;
    }
    for(int i = 1; i <= idx + 1; i++){
        buf[i] += buf[i - 1];
    }
    int p = 1;
    while(p <= idx){
        if(buf[p]){
            int q = p;
            while(buf[q]){
                q++;
            }
            printf("%lld %lld\n", mp2[p], mp2[q - 1]);
            p = q;
        }
        else{
            p++;
        }
    }
    return 0;
}
