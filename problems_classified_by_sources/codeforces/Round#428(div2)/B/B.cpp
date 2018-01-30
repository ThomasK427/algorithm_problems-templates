#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k;
    while(~scanf("%d%d", &n, &k)){
        for(int i = 0; i < k; i++){
            scanf("%d", ar + i);
        }
        int x = n, y = 2 * n;
        for(int i = 0; i < k; i++){
            if(ar[i] >= 4){
                int p = ar[i] / 4, q = min(x, p);
                x -= q;
                ar[i] -= 4 * q;
                if(x == 0){
                    break;
                }
            }
        }
        bool ans = false;
        if(x > 0){
            for(int i = 0; i < k; i++){
                if(ar[i] == 3){
                    if(x > 0){
                        x--;
                        ar[i] = 0;
                    }
                    else{
                        if(y > 0){
                            y--;
                            ar[i] = 1;
                        }
                        else{
                            ans = false;
                            goto HERE;
                        }
                    }
                }
            }
            int cnt1 = 0, cnt2 = 0;
            for(int i = 0; i < k; i++){
                if(ar[i] == 1){
                    cnt1++;
                }
                else if(ar[i] == 2){
                    cnt2++;
                }
            }
            if(x + y >= cnt2){
                if(cnt1 + cnt2 <= 2 * x + y){
                    ans = true;
                    goto HERE;
                }
                else{
                    ans = false;
                    goto HERE;
                }
            }
            else{
                cnt2 -= (x + y);
                cnt2 *= 2;
                if(cnt1 + cnt2 <= x){
                    ans = true;
                    goto HERE;
                }
                else{
                    ans = false;
                    goto HERE;
                }
            }
        }
        else{
            int sum = 0;
            for(int i = 0; i < k; i++){
                sum += (ar[i] + 1) / 2;
            }
            if(sum <= y){
                ans = true;
                goto HERE;
            }
            else{
                ans = false;
                goto HERE;
            }
        }
        HERE:;
        if(ans){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
