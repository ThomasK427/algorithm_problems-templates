#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL Sqrt(LL x)
{
    LL low = 0, high = x;
    while(low <= high){
        LL mid = (low + high) >> 1;
        if(mid * mid < x){
            low = mid + 1;
        }
        else if(mid * mid > x){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    LL N;
    cin >> N;
    bool flag = false;
    for(LL i = 0; i * i <= N; i++){
        LL j = Sqrt(N - i * i);
        if(i <= j){
            cout << i << " " << j << endl;
            flag = true;
        }
    }
    if(!flag){
        cout << "No Solution" << endl;
    }
    return 0;
}
