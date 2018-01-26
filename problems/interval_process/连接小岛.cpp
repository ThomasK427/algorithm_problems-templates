/**
*
*51nod1460
*
*有n个小岛，每一个小岛是直线型的，他们不相互相交，第i个小岛所占的区间是[li, ri],
*而且, ri <  li+1  对于所有的 1 ≤ i ≤ n-1。现在要将相邻的小岛用桥连接起来。现在有
*一条桥的长度是a，第i个岛和第i+1个岛能够连接的条件是，存在x,y使得 li ≤ x ≤ ri,
*li+1 ≤ y ≤ ri+1  且 y - x = a成立。
*现在有m条桥，每条桥最多被使用一次，问能否把这些岛连接起来。
*
*Input
*
*单组测试数据。
*第一行有两个整数n (2 ≤ n ≤ 2*10^5) 和 m (1 ≤ m ≤ 2*10^5)，表示岛的数目和桥的数目。
*接下来n行，每行有两个整数 li 和 ri (1 ≤ li ≤ ri ≤ 10^18)，表示岛的两个端点。
*接下来一行有m个整数 a1, a2, ..., am (1 ≤ ai ≤ 10^18)，表示每一条桥的长度。
*
*Output
*
*如果能够将n座岛连接起来输出YES，否则输出NO。
*
*/

/**
*
*问题转化为：能否在m个数中找到n-1个数，使对每个区间，都有一个数在这个区间中
*
*贪心思路1：把区间按右端点从小到大排序，右端点相同的按左端点从小到大排序
*对每个区间，选择在其中的最小的数
*
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

struct Node{
    LL a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.b == e2.b){
            return e1.a < e2.a;
        }
        else{
            return e1.b < e2.b;
        }
    }
}E[maxn];
multiset<LL> st;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    LL x, y, l, r;
    scanf("%lld%lld", &x, &y);
    for(int i = 0; i < n - 1; i++){
        scanf("%lld%lld", &l, &r);
        E[i].a = l - y;
        E[i].b = r - x;
        x = l;
        y = r;
    }
    for(int i = 0; i < m; i++){
        scanf("%lld", &x);
        st.insert(x);
    }
    //把区间按右端点从小到大排序，右端点相同的按左端点从小到大排序
    sort(E, E + n - 1);
    bool flag = true;
    for(int i = 0; i < n - 1; i++){     //选择大于等于左端点的最小的数
        multiset<LL>::iterator it = st.lower_bound(E[i].a);
        if((it == st.end()) || (*it > E[i].b)){
            flag = false;
            break;
        }
        st.erase(it);
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
