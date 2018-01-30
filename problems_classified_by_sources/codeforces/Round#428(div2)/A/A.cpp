#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

int ar[maxn];

int flo(int x)
{
    int y = x / 2;
    if(x & 1)y++;
    return y;
}

int main()
{
//    //freopen("test.txt", "r", stdin);
//    int n, k;
//    while(~scanf("%d%d", &n, &k)){
//        for(int i = 1; i <= n; i++){
//            scanf("%d", ar + i);
//        }
//        int sum = 0;
//        for(int i = 1; i <= n; i++){
//            sum += ar[i];
//            int x = min(8, sum);
//            k -= x;
//            sum -= x;
//            if(k <= 0){
//                printf("%d\n", i);
//                break;
//            }
//        }
//        if(k > 0){
//            puts("-1");
//        }
//    }
    int x;
    while(cin >> x){
        cout << flo(x) << endl;
    }
    return 0;
}
