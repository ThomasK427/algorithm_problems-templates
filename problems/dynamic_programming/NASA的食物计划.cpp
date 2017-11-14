/**
*二维限制的0-1背包 vijos1334 
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxv = 405;
const int maxm = 405;

int v[maxn], m[maxn], c[maxn];
int dp[maxv][maxm];

int main()
{
	int V, M, N;
	scanf("%d%d%d", &V, &M, &N);
	for(int i = 1; i <= N; i++){
		scanf("%d%d%d", v + i, m + i, c + i);
	}
	for(int i = 1; i <= N; i++){
		for(int j = V; j >= v[i]; j--){
			for(int k = M; k >= m[i]; k--){
				dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + c[i]);
			}
		}
	}
	printf("%d\n", dp[V][M]);
	return 0;
}
