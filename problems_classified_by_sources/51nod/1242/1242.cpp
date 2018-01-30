#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const LL Q = 1000000009;
const int maxn = 1005;

struct Matrix{
    LL a[3][3];
};

void multi(Matrix& m1, Matrix m2)
{
    Matrix m;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            m.a[i][j] = 0;
            for(int k = 1; k <= 2; k++){
                m.a[i][j] = (m.a[i][j] + m1.a[i][k] * m2.a[k][j] % Q + Q) % Q;
            }
        }
    }
    m1 = m;
}

int f[10];

int main()
{
    //freopen("test.txt", "r", stdin);
    f[1] = 1;
    f[2] = 1;
    f[3] = 2;
    LL N;
    cin >> N;
    if(N <= 3){
        cout << f[N] << endl;
        return 0;
    }
    Matrix base, res;
    base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
    base.a[2][2] = 0;
    res.a[1][1] = res.a[2][2] = 1;
    res.a[1][2] = res.a[2][1] = 0;
    N--;
    while(N > 0){
        if(N & 1){
            multi(res, base);
        }
        N >>= 1;
        multi(base, base);
    }
    cout << res.a[1][1] << endl;
    return 0;
}
