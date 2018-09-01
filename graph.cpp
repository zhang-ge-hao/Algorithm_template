#include "basic.h"
const int maxn=2e5+5;
ll n;
ll head[maxn];
bool vis[maxn];
struct edge{
    ll to,next,len;
    edge(ll a=0,ll b=-1,ll c=0){
        to = a; next = b; len = c;
    }
};
edge E[maxn*2];
struct graph{
    ll eid;
    ~graph(){
    }
    graph(){
        memset(head,-1,sizeof(head));
        memset(vis,0, sizeof(vis));
        eid = 0;
    }
    void add(ll h,ll t,ll len=1){
        E[eid] = edge(t,head[h],len);
        head[h] = eid ++;
    }
};