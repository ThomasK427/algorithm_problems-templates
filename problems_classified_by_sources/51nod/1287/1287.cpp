#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int ar[maxn];
int M, N;
map<int, int> mp;

int main()
{
    scanf("%d%d", &M, &N);
    for(int i = 1; i <= M; i++){
        scanf("%d", ar + i);
        if(mp.lower_bound(ar[i]) == mp.end()){
            mp[ar[i]] = i;
        }
    }
    for(int i = 1; i <= N; i++){
        int x;
        scanf("%d", &x);
        if(x <= ar[1]){
            continue;
        }
        else{
            map<int, int>::iterator it = mp.lower_bound(x);
            if(it == mp.end()){
                continue;
            }
            else{
                int p = it->second - 1;
                ar[p]++;
                if(mp.lower_bound(ar[p])->second > p){
                    mp[ar[p]] = p;
                }
            }
        }
    }
    for(int i = 1; i <= M; i++){
        printf("%d\n", ar[i]);
    }
    return 0;
}
