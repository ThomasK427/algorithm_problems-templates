#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[] = {1, 2, 3, 5, 7, 11};
set<int> st;

int main()
{
    //freopen("test.txt", "r", stdin);
    for(int i = 0; i < 6; i++){
        st.insert(ar[i]);
    }
    int q, n;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        if(st.count(n)){
            puts("-1");
        }
        else{
            if(n & 1){
                n -= 9;
                printf("%d\n", n / 4 + 1);
            }
            else{
                printf("%d\n", n / 4);
            }
        }
    }
    return 0;
}
