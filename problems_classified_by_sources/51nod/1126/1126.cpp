#include <bits/stdc++.h>
using namespace std;
const int Q = 7;

struct Matrix{
    int a[3][3];
};

void multi(Matrix& m1, Matrix m2)
{
    Matrix m;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            m.a[i][j] = 0;
            for(int k = 1; k <= 2; k++){
                m.a[i][j] = (m.a[i][j] + m1.a[i][k] * m2.a[k][j]) % Q;
            }
        }
    }
    m1 = m;
}

int main()
{
    int A, B, N;
    cin >> A >> B >> N;
    while(A < 0){
        A += Q;
    }
    while(B < 0){
        B += Q;
    }
    Matrix base, res;
    base.a[1][1] = A;
    base.a[1][2] = B;
    base.a[2][1] = 1;
    base.a[2][2] = 0;
    res.a[1][1] = 1;
    res.a[1][2] = 0;
    res.a[2][1] = 0;
    res.a[2][2] = 1;
    N--;
    while(N > 0){
        if(N & 1){
            multi(res, base);
        }
        N >>= 1;
        multi(base, base);
    }
    cout << (res.a[2][1] + res.a[2][2]) % Q << endl;
    return 0;
}
