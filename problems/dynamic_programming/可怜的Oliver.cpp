#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

struct Node{
	int p, t;
	friend bool operator<(const Node& a, const Node& b){
		return a.p < b.p;
	}
}E[maxn];

int dp[maxn];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= K; i++){
		scanf("%d%d", &E[i].p, &E[i].t);
	}
	E[0].p = 0;
	sort(E + 1, E + K + 1);
	int j = K;
	dp[N + 1] = 0;
	for(int i = N; i >= 1; i--){
		if(i == E[j].p){
			while(i == E[j].p){
				dp[i] = max(dp[i], dp[i + E[j--].t]);
			}
		}
		else{
			dp[i] = dp[i + 1] + 1;
		}
	}
	printf("%d\n", dp[1]);
	return 0;
}
