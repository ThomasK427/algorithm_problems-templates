#include <bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    int sh, sm, ss;
    int th, tm, ts;
    Node(){}
    Node(string name, int sh, int sm, int ss, int th, int tm, int ts){
        this->name = name;
        this->sh = sh;
        this->sm = sm;
        this->ss = ss;
        this->th = th;
        this->tm = tm;
        this->ts = ts;
    }
};

bool cmp1(const Node& a, const Node& b){
    if(a.sh != b.sh){
        return a.sh < b.sh;
    }
    else if(a.sm != b.sm){
        return a.sm < b.sm;
    }
    else{
        return a.ss < b.ss;
    }
}

bool cmp2(const Node& a, const Node& b){
    if(a.th != b.th){
        return a.th > b.th;
    }
    else if(a.tm != b.tm){
        return a.tm > b.tm;
    }
    else{
        return a.ts > b.ts;
    }
}

int main()
{
    char str[1000];
    int sh, sm, ss, th, tm, ts;
    vector<Node> v;
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%s %d:%d:%d %d:%d:%d", str, &sh, &sm, &ss, &th, &tm, &ts);
        v.push_back(Node(string(str), sh, sm, ss, th, tm, ts));
    }
    sort(v.begin(), v.end(), cmp1);
    printf("%s ", v[0].name.c_str());
    sort(v.begin(), v.end(), cmp2);
    printf("%s\n", v[0].name.c_str());
    return 0;
}
