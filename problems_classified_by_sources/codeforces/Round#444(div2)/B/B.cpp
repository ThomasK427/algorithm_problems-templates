#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int br[4];
int ar[4][10];
int n;
unordered_set<int> st;

void dfs(int k, int cur){
    if(k >= n){
        st.insert(cur);
        return;
    }
    dfs(k + 1, cur);
    for(int i = 0; i < 6; i++){
        dfs(k + 1, cur * 10 + ar[br[k]][i]);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d", &ar[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        br[i] = i;
    }
    do{
        dfs(0, 0);
    }while(next_permutation(br, br + n));
    for(int i = 0; ; i++){
        if(!st.count(i)){
            printf("%d\n", i - 1);
            break;
        }
    }
    return 0;
}
