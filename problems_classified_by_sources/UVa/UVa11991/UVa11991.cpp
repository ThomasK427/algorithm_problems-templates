#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

int ar[maxn];
vector<int> vec[maxn];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= n; i++){
            vec[i].clear();
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
            vec[ar[i]].push_back(i);
        }
        while(m--){
            int k, v;
            scanf("%d%d", &k, &v);
            if(vec[v].size() < k){
                puts("0");
            }
            else{
                printf("%d\n", vec[v][k-1]);
            }
        }
    }
    return 0;
}
