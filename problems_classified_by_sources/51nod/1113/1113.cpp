#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1000000007;
const int maxn = 105;

struct Matrix{
    int n;
    LL e[maxn][maxn];
};

void multi(Matrix& m1, Matrix m2)
{
    Matrix m;
    m.n = m1.n;
    for(int i = 1; i <= m.n; i++){
        for(int j = 1; j <= m.n; j++){
            m.e[i][j] = 0LL;
            for(int k = 1; k <= m.n; k++){
                m.e[i][j] = (m.e[i][j] + m1.e[i][k] * m2.e[k][j] % Q + Q) % Q;
            }
        }
    }
    m1 = m;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    Matrix base, res;
    base.n = N;
    res.n = N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%lld", &base.e[i][j]);
            base.e[i][j] = (base.e[i][j] + Q) % Q;
            res.e[i][j] = (i == j ? 1 : 0);
        }
    }
    while(M){
        if(M & 1){
            multi(res, base);
        }
        multi(base, base);
        M >>= 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%lld%c", res.e[i][j], (j == N ? '\n' : ' '));
        }
    }
    return 0;
}
