#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL v[100];

int main()
{
    LL w, m;
    scanf("%lld%lld", &w, &m);
    int n = 0;
    while(m){
        v[n++] = m % w;
        m /= w;
    }
    bool flag = true;
    for(int i = 0; i <= n + 1; i++){
        if(v[i] == 0 || v[i] == 1){
            continue;
        }
        else if(v[i] == w - 1){
            v[i + 1]++;
        }
        else{
            flag = false;
            break;
        }
    }
    puts(flag ? "YES" : "NO");
    return 0;
}
