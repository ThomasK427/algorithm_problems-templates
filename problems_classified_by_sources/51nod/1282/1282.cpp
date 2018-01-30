#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

int N, M, P;
unordered_map<int, int> mp;
int ar[maxn];
int br[maxn];

int Hash(){
    int p = 0;
    for(int i = 0; i < M; i++){
        if(br[i] > br[p]){
            p = i;
        }
    }
    int ans = 0;
    for(int i = p, k = 1; k <= M; i = (i + 1) % M, k++){
        ans += k * br[i];
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &N, &M, &P);
    if(M == 1){
        printf("%d\n", N * (N - 1) / 2);
        return 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", ar + j);
        }
        sort(ar, ar + M);
        for(int j = 0; j < M; j++){
            br[j] = (ar[(j + 1) % M] - ar[j] + P) % P;
        }
        mp[Hash()]++;
    }
    int ans = 0;
    for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        int n = it->second;
        ans += n * (n - 1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}
