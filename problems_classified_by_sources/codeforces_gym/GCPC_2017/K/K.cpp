#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct node{
    string s;
    int c;
    bool operator <(const node& u)const {
        return c>u.c;
    }
}a[10010];
int main()
{
    int n,d,k;
    scanf("%d%d%d",&n,&d,&k);
    for(int i=0;i<n;i++){
        cin>>a[i].s>>a[i].c;
    }
    sort(a,a+n);
    vector<int>ans;
    ans.clear();
    int cc=0;
    for(int i=0;i<n;i++){
        if(cc>=d) break;
        cc+=a[i].c;
        k--;
        ans.push_back(i);
    }
    if(k<0||cc<d) puts("impossible");
    else{
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<a[ans[i]].s<<", YOU ARE FIRED!"<<endl;
    }

}
