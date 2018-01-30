#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Q = 107;
const int maxn = 5;

int A[maxn][maxn], B[maxn][maxn];
int getPoint(int u, int v){
    if(u == v){
        return 0;
    }
    else if((u == 3 && v == 2) || (u == 2 && v == 1) || (u == 1 && v == 3)){
        return 1;
    }
    else{
        return -1;
    }
}
void trans(int& a, int& b){
    int u = a, v = b;
    a = A[u][v];
    b = B[u][v];
}
int Hash(int u, int v){
    return u * Q + v;
}

int main()
{
    LL k;
    int a, b;
    while(~scanf("%lld%d%d", &k, &a, &b)){
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                scanf("%d", &A[i][j]);
            }
        }
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                scanf("%d", &B[i][j]);
            }
        }
        map<int, int> mp;
        int u = a, v = b, T = 0, ed = 0;
        for(int i = 1; ; i++){
            mp[Hash(u, v)] = i;
            trans(u, v);
            if(mp.count(Hash(u, v))){
                ed = i;
                T = i - mp[Hash(u, v)] + 1;
                break;
            }
        }
        LL tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < T; i++){
            int p = getPoint(u, v);
            if(p == 1){
                tmp1++;
            }
            else if(p == -1){
                tmp2++;
            }
            trans(u, v);
        }
        if(k <= ed){
            LL ans1 = 0, ans2 = 0;
            for(int i = 1; i <= k; i++){
                int p = getPoint(a, b);
                if(p == 1){
                    ans1++;
                }
                else if(p == -1){
                    ans2++;
                }
                trans(a, b);
            }
            printf("%lld %lld\n", ans1, ans2);
            continue;
        }
        LL rem = k - ed + 1, ans1 = rem / T * tmp1, ans2 = rem / T * tmp2;
        for(int i = 1; i < ed + rem % T; i++){
            int p = getPoint(a, b);
            if(p == 1){
                ans1++;
            }
            else if(p == -1){
                ans2++;
            }
            trans(a, b);
        }
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}


