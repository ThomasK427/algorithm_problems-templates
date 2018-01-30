#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL lim = 1000000000000000000;

vector<LL> a2, a3, a5, v;

void CreateTable()
{
    for(LL p = 1; p <= lim; p *= 2){
        a2.push_back(p);
    }
    for(LL p = 1; p <= lim; p *= 3){
        a3.push_back(p);
    }
    for(LL p = 1; p <= lim; p *= 5){
        a5.push_back(p);
    }
    for(int i = 0; i < a2.size(); i++){
        LL p = a2[i];
        for(int j = 0; j < a3.size(); j++){
            LL q = a3[j];
            if(p * q > lim){
                break;
            }
            for(int k = 0; k < a5.size(); k++){
                LL r = a5[k];
                if(p * q * r > lim){
                    break;
                }
                else{
                    if(p * q * r > 1){
                        v.push_back(p * q * r);
                    }
                }
            }
        }
    }
    sort(v.begin(), v.end());
}

int main()
{
    CreateTable();
    int T;
    scanf("%d", &T);
    while(T--){
        LL N;
        scanf("%lld", &N);
        printf("%lld\n", *lower_bound(v.begin(), v.end(), N));
    }
    return 0;
}
