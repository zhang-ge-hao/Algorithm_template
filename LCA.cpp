#include "basic.h"
struct LCA_rmq{
    RMQ *r;
    ll *n_ft,*t_n,*n_p,*n_r,*r_n,dfst,nid,maxn;
    LCA_rmq(ll Maxn,ll maxl){
        maxn = Maxn,r = new RMQ(maxl);
        n_ft = new ll[maxn],n_p  = new ll[maxn];
        n_r  = new ll[maxn],r_n  = new ll[maxn];
        t_n  = new ll[maxl];
    }
    ~LCA_rmq(){
        delete[] n_ft;
        delete[] n_p;
        delete[] n_r;
        delete[] r_n;
        delete[] t_n;
        delete r;
    }
    void init(ll nodecon,const graph &T){
        dfst = nid = 0;
        memset(n_r,-1,sizeof(ll)*maxn);
        for(ll i=1;i<=nodecon;i++)if(n_r[i] == -1){
            dfs(i,-1,0,T);
            t_n[dfst ++] = -1;
        }
        r->init(t_n,dfst);
    }
    void dfs(ll r,ll f,ll p,const graph &T){
        ll *head = T.head; edge *E = T.E;
        n_r[r] = nid,r_n[nid++] = r;
        n_p[r] = p,n_ft[r] = dfst,t_n[dfst ++] = n_r[r];
        for(ll i=head[r];i!=-1;i=E[i].next){
            if(E[i].to == f)continue;
            dfs(E[i].to,r,p+E[i].len,T);
            t_n[dfst ++] = n_r[r];
        }
    }
    ll find_path(ll a,ll b){
        if(n_ft[a] > n_ft[b])swap(a,b);
        ll pa = n_p[a],pb = n_p[b];
        ll lca = r->find(n_ft[a],n_ft[b]+1);
        if(lca == -1)return -1;
        ll pc = n_p[r_n[lca]];
        return pa+pb-2*pc;
    }
};
