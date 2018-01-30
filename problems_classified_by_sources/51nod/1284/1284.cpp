#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int ar[4] = {2, 3, 5, 7};

int main()
{
    LL N;
    cin >> N;
    LL ans = 0;
    for(int S = 0; S < 16; S++){
        LL product = 1, cnt = 0;
        for(int i = 0; i < 4; i++){
            if(S & (1 << i)){
                product *= ar[i];
                cnt++;
            }
        }
        if(cnt & 1){
            ans -= N / product;
        }
        else{
            ans += N / product;
        }
    }
    cout << ans << endl;
    return 0;
}
