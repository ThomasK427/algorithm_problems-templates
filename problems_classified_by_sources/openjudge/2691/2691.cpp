#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int ar[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int kase = 0; kase < n; kase++){
        int k;
        scanf("%d", &k);
        for(int i = 1; i <= k; i++){
            scanf("%d", ar + i);
        }
        ar[0] = ar[2];
        ar[k + 1] = ar[k - 1];
        vector<int> v;
        for(int i = 1; i <= k; i++){
            if((ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) || (ar[i] < ar[i - 1] && ar[i] < ar[i + 1])){
                v.push_back(i - 1);
            }
        }
        for(int i = 0; i < v.size(); i++){
            printf("%d%c", v[i], i + 1 == v.size() ? '\n': ' ');
        }
    }
    return 0;
}
