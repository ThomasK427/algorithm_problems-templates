#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL inf = 0x3f3f3f3f;
const int maxn = 10005;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

struct fra{
    LL a, b;
    fra(){
        a = -INT_MAX;
        b = 1;
    }
    fra(LL aa, LL bb):a(aa), b(bb){
        LL g = gcd(a, b);
        a /= g;
        b /= g;
    }
    friend bool operator<(const fra& e1, const fra& e2){
        return double(e1.a) / e1.b < double(e2.a) / e2.b;
    }
    friend bool operator==(const fra& e1, const fra& e2){
        return e1.a * e2.b == e2.a * e1.b;
    }
};

struct Node{
    LL x, y, idx;
    friend bool operator<(const Node& a, const Node& b){
        return a.x < b.x;
    }
    friend fra ks(const Node& a, const Node& b){
        LL dx = b.x - a.x, dy = b.y - a.y, g = gcd(dx, dy);
        return fra(dy, dx);
    }
}E[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld", &E[i].x, &E[i].y);
        E[i].idx = i + 1;
    }
    sort(E, E + N);
    fra ans;
    for(int i = 0; i < N - 1; i++){
        fra tmp = ks(E[i], E[i + 1]);
        if(ans < tmp){
            ans = tmp;
        }
    }
    for(int i = 0; i < N - 1; i++){
        fra tmp = ks(E[i], E[i + 1]);
        if(ans == tmp){
            printf("%lld %lld\n", E[i].idx, E[i + 1].idx);
        }
    }
    return 0;
}
