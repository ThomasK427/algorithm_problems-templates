#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int arr[N];
int n , x, y;
int frq[1000100];

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

long long check(int g){
	long long all = 0 ;
	for(int i=0;i<n;i++){
		if(arr[i] % g != 0){
			int cur = arr[i] / g + 1;
			cur = cur * g;
			int mi = cur - arr[i];
			all+=min((long long)y*(long long)mi,(long long)x);
		}
	}
	return all;
}

int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&x,&y);;
	vector<int> v;
	v.push_back(2);
	int mx = 0 ;
	int cur = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		frq[arr[i]]++;
		if(frq[arr[i]] > mx){
			mx = frq[arr[i]];
			cur = arr[i];
		}
	}
	for(int j=1;j*j<=cur;j++){
		if(cur % j == 0){
			v.push_back(j);
			v.push_back(cur/j);
		}
	}
	long long cost = 1e18;
	for(int i=0;i<v.size();i++){
		if(v[i] == 1) continue;
		cost = min(cost,check(v[i]));
	}
	cout << cost << endl;
	return 0;
}

