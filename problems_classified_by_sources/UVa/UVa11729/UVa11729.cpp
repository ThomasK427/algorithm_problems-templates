#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;

struct Job{
    int B, J;
    friend bool operator<(const Job& jb1, const Job& jb2){
        return jb1.J > jb2.J;
    }
}ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int kase = 0;
    int N;
    while(~scanf("%d", &N) && N){
        for(int i = 0; i < N; i++){
            scanf("%d%d", &ar[i].B, &ar[i].J);
        }
        sort(ar, ar + N);
        int s = 0, ans = 0;
        for(int i = 0; i < N; i++){
            s += ar[i].B;
            ans = max(ans, s + ar[i].J);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
