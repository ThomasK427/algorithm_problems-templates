/*

51nod1460

��n��С����ÿһ��С����ֱ���͵ģ����ǲ��໥�ཻ����i��С����ռ��������[li, ri],
����, ri <  li+1  �������е� 1 �� i �� n-1������Ҫ�����ڵ�С����������������������
һ���ŵĳ�����a����i�����͵�i+1�����ܹ����ӵ������ǣ�����x,yʹ�� li �� x �� ri,
li+1 �� y �� ri+1  �� y - x = a������
������m���ţ�ÿ������౻ʹ��һ�Σ����ܷ����Щ������������

Input

����������ݡ�
��һ������������n (2 �� n �� 2*10^5) �� m (1 �� m �� 2*10^5)����ʾ������Ŀ���ŵ���Ŀ��
������n�У�ÿ������������ li �� ri (1 �� li �� ri �� 10^18)����ʾ���������˵㡣
������һ����m������ a1, a2, ..., am (1 �� ai �� 10^18)����ʾÿһ���ŵĳ��ȡ�

Output

����ܹ���n���������������YES���������NO��

*/

/*

����ת��Ϊ���ܷ���m�������ҵ�n-1������ʹ��ÿ�����䣬����һ���������������

̰��˼·1�������䰴�Ҷ˵��С���������Ҷ˵���ͬ�İ���˵��С��������
��ÿ�����䣬ѡ�������е���С����

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
    //�����䰴�Ҷ˵��С���������Ҷ˵���ͬ�İ���˵��С��������
    sort(E, E + n - 1);
    bool flag = true;
    for(int i = 0; i < n - 1; i++){     //ѡ����ڵ�����˵����С����
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
