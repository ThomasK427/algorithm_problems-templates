#include <bits/stdc++.h>
using namespace std;

map<int, double> mp[2], mmp;

int main()
{
    for(int i = 0; i < 2; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int n;
            double a;
            scanf("%d%lf", &n, &a);
            mp[i][n] = a;
        }
    }
    for(auto u : mp[0]){
        for(auto v : mp[1]){
            mmp[u.first + v.first] += u.second * v.second;
        }
    }
    vector<map<int, double>::iterator> v;
    for(map<int, double>::iterator it = mmp.begin(); it != mmp.end(); it++){
        if(abs(it->second) < 1e-6){
            v.push_back(it);
        }
    }
    for(int i = 0; i < v.size(); i++){
        mmp.erase(v[i]);
    }
    printf("%d", int(mmp.size()));
    for(map<int, double>::reverse_iterator rit = mmp.rbegin(); rit != mmp.rend(); rit++){
        printf(" %d %.1f", rit->first, rit->second);
    }
    putchar('\n');
    return 0;
}
