#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL f(LL n){
    return n * n + 2 * n;
}

LL binSearch(LL x){
    LL low = 0, high = 31622776;
    while(low < high){
        LL mid = low + high >> 1;
        if(f(mid) >= x){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    LL n;
    cin >> n;
    cout << n - binSearch(n)<< endl;
    return 0;
}
