#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

/*

̰��˼·2����̰��˼·1�Գƣ���
�����䰴��˵��С����������˵���ͬ�İ��Ҷ˵��С��������
�Ӻ���ǰ����ÿ�����䣬ѡ�������е�������

*/

struct Node{
    LL a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.a == e2.a){
            return e1.b < e2.b;
        }
        else{
            return e1.a < e2.a;
        }
    }
}E[maxn];
multiset<LL, greater<LL> > st;

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
    sort(E, E + n - 1);
    bool flag = true;
    for(int i = n - 2; i >= 0; i--){
        multiset<LL>::iterator it = st.lower_bound(E[i].b);
        if((it == st.end()) || (*it < E[i].a)){
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
