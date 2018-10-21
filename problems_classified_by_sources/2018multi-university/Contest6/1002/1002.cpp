#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 1000005;

int cnt[maxn];
int n, k;
LL fac[maxn], fib[maxn];

LL solution = 0, type = 0, ans = 0;

LL qpow(LL a, LL n){
    LL base = a % Q, res = 1;
    while(n){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

LL inv(LL x){
    return qpow(x, Q - 2);
}

void dfs(int t, int d){
    if(d == k){
        cnt[d] = t;
        type++;
        LL tmp = fac[n];
        for(int i = 1; i <= k; i++){
            tmp /= fac[cnt[i]];
        }
        solution += tmp;
        int flag = 0;
        //cout << "k = " << k << endl;
        for(int i = 1; i <= k; i++){
            //cout << cnt[i] << " ";
            if(cnt[i] == 0){
                continue;
            }else if(flag == 0){
                flag = cnt[i];
            }else if(flag == cnt[i]){
                continue;
            }else{
                flag = -1;
                break;
            }
        }
        cout << endl;
        cout << flag << endl;
        LL ct = 1;
        if(flag != -1){
            ct = (qpow(2, fib[flag]) - 1 + Q) % Q;
        }
        cout << ct << endl;
        system("pause");
        ans += ct * tmp;
    }else{
        for(int i = 0; i <= t; i++){
            cnt[d] = i;
            dfs(t - i, d + 1);
        }
    }
}

int main()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        fib[i] = (fib[i - 1] + fib[i - 2]) % Q;
    }
    fac[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fac[i] = fac[i - 1] * i % Q;
    }
    n = 6;
    k = 8;
    dfs(n, 1);
    ans = ans * inv(qpow(k, n)) % Q;
    cout << solution << " " << qpow(k, n) << endl;
    cout << ans << endl;
    return 0;
}
