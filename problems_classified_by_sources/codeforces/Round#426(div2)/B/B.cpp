#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;

char str[maxn];
int n, k;

int ar[30][2];
int vis[26];
int br[maxn];
int cr[maxn];

int main()
{
    while(~scanf("%d%d", &n, &k)){
        scanf("%s", str + 1);
        memset(ar, 0, sizeof(ar));
        memset(vis, 0, sizeof(vis));
        memset(br, 0, sizeof(br));
        memset(cr, 0, sizeof(cr));
        for(int i = 1; i <= n; i++){
            char ch = str[i];
            vis[ch - 'A']++;
            if(vis[ch - 'A'] == 1){
                ar[ch - 'A'][0] = i;
            }
            else{
                ar[ch - 'A'][1] = i;
            }
        }
        for(int i = 0; i < 26; i++){
            if(vis[i] == 1){
                br[ar[i][0]]++;
                br[ar[i][0] + 1]--;
            }
            else if(vis[i] > 1){
                br[ar[i][0]]++;
                br[ar[i][1] + 1]--;
            }
        }
        int M = 0;
        cr[0] = 0;
        for(int i = 1; i < maxn; i++){
            cr[i] = cr[i-1] + br[i];
            M = max(M, cr[i]);
        }
        if(M > k){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}

