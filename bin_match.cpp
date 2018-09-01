#include "basic.h"

bool binMatch(ll x,ll *os,bool *used,const graph &G){
    ll *head = G.head; edge *E = G.E;
    for(ll i=head[x];i!=-1;i=E[i].next){
        ll s = E[i].to;
        if(!used[s]){
            used[s]=1;
            if(os[s]==-1||binMatch(os[s],os,used,G)){
                os[s]=x;
                return 1;
            }
        }
    }
    return 0;
}
ll mainBinMatch(ll nodecon,ll *other_side,const graph &G){
    ll res = 0;
    static bool *used = new bool[G._maxn];
    memset(other_side,-1,sizeof(ll)*G._maxn);
    for(ll i=1;i<=nodecon;i++){
        memset(used,0,sizeof(bool)*G._maxn);
        if(binMatch(i,other_side,used,G))res ++;
    }
    return res;
}
