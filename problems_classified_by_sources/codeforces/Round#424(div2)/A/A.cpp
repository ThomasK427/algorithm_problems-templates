#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn];
int br[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    if(n == 1){
        puts("YES");
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(ar[i] - ar[i-1] > 0){
            br[i] = 1;
        }
        else if(ar[i] - ar[i-1] == 0){
            br[i] = 0;
        }
        else{
            br[i] = -1;
        }
    }
    for(int i = 2; i < n; i++){
        if(br[i] > br[i-1]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
