#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;

int w[maxn];
int L, R;

int BinSearch(int x)
{
    int low = L, high = R;
    while(low < high){
        int mid = (low + high) >> 1;
        if(w[mid] >= x){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int mi = INF;
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", w + i);
        w[i] = min(w[i], mi);
        mi = min(mi, w[i]);
    }
    reverse(w, w + N);
    L = 0;
    R = N;
    int ans = 0;
    for(int i = 0; i < M; i++){
        int x;
        scanf("%d", &x);
        int y = BinSearch(x);
        if(y == N){
            break;
        }
        else{
            ans++;
            L = y + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
