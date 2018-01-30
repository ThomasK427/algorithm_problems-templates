#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    //freopen("test.txt", "r", stdin);
    LL ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    LL len1 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    LL len2 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
    LL w = (ay - cy) * (bx - cx) - (by - cy) * (ax - cx);
    if(len1 == len2 && w != 0){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
