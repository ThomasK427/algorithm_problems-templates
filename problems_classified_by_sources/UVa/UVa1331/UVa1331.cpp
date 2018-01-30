#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 60;

struct Node{
    int x, y;
}E[maxn];
int dp[maxn][maxn];
int m;

inline int area(const Node& a, const Node& b, const Node& c){
    int dx1 = b.x - a.x, dy1 = b.y - a.y, dx2 = c.x - a.x, dy2 = c.y - a.y;
    return abs(dx1 * dy2 - dx2 * dy1);
}

inline int s(int i, int j, int k){
    return area(E[i], E[j], E[k]);
}

bool judge(int i, int j, int k){
    int s1 = s(i, j, k);
    for(int v = 1; v <= m; v++){
        if(v == i || v == j || v == k){
            continue;
        }
        int s2 = s(i, j, v) + s(i, v, k) + s(v, j, k);
        if(s1 == s2){
            return false;
        }
    }
    return true;
}

int d(int i, int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    ans = INF;
    if(i + 1 == j){
        ans = 0;
    }
    for(int k = i + 1; k < j; k++){
        if(judge(i, j, k)){
            ans = min(ans, max(s(i, j, k), max(d(i, k), d(k, j))));
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &E[i].x, &E[i].y);
        }
        memset(dp, -1, sizeof(dp));
        printf("%.1f\n", d(1, m) / 2.0);
    }
    return 0;
}
