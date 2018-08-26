#include "basic.h"
struct RMQ{
    ll **st,maxl,maxh; double log2;
    RMQ(const ll &Maxl){
        log2 = log(2);
        maxl = Maxl;
        maxh = log(maxl)/log2;
        st = new ll*[maxh+1];
        for(ll i=0;i<=maxh;i++)
            st[i] = new ll[maxl+1-(1<<i)];
    }
    ~RMQ(){
        for(ll i=0;i<=maxh;i++)delete[] st[i];
        delete[] st;
    }
    void init(ll *arr,const ll &len){
        ll col = log(len)/log2;
        for(ll i=0;i<len;i++)st[0][i] = arr[i];
        for(ll i=1;i<=col;i++)for(ll j=0;j<=len-(1<<i);j++)
            st[i][j] = comp(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    ll find(ll lo,ll hi){ // zuo bi you kai
        ll col = log(hi-lo)/log2;
        return comp(st[col][lo],st[col][hi-(1<<col)]);
    }
    ll comp(ll a,ll b){
        return a<b?a:b;
    }
};
