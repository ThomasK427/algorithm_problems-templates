#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;

int n, m;

map<int, int> mpr, mp;

int main()
{
    while(~scanf("%d%d", &n, &m)){
        mpr.clear();
        mp.clear();
        int b = int(sqrt(m) + 2.0);
        for(int i = 2; i <= b; i++){
            if(m % i == 0){
                int k = 0;
                while(m % i == 0){
                    k++;
                    m /= i;
                }
                mpr[i] = k;
            }
        }
        if(m > 1)mpr[m] = 1;
        vector<int> ans;
        for(int i = 1; i < n; i++){
            int x = n - i;
            b = int(sqrt(x) + 2.0);
            for(int j = 2; j <= b; j++){
                if(x % j == 0){
                    int k = 0;
                    while(x % j == 0){
                        k++;
                        x /= j;
                    }
                    mp[j] += k;
                }
            }
            if(x > 1)mp[x]++;
            x = i;
            b = int(sqrt(x) + 2.0);
            for(int j = 2; j <= b; j++){
                if(x % j == 0){
                    int k = 0;
                    while(x % j == 0){
                        k++;
                        x /= j;
                    }
                    mp[j] -= k;
                }
            }
            if(x > 1)mp[x]--;
            bool flag = true;
            for(map<int, int>::iterator it = mpr.begin(); it != mpr.end(); it++){
                if(it->second > mp[it->first]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i+1);
            }
        }
        printf("%d\n", int(ans.size()));
        for(int i = 0; i < int(ans.size()); i++){
            if(i > 0) putchar(' ');
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
