#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int ar[maxn];
map<int, int> mp;

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
        mp[ar[i] % m]++;
    }
    int p = -1;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second >= k){
            p = it->first;
            break;
        }
    }
    if(p < 0){
        puts("No");
    }
    else{
        puts("Yes");
        for(int i = 0; i < n; i++){
            if(ar[i] % m == p){
                printf("%d", ar[i]);
                k--;
                if(k){
                    putchar(' ');
                }
                else{
                    putchar('\n');
                    break;
                }
            }
        }
    }
    return 0;
}
