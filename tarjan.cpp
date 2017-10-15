ll vid,*dfn,*low,*insta,*block;
stack<ll> sta;
void tarjan(ll r,vector<vector<ll>> &res,const graph &G){
    ll *head = G.head;edge *E = G.E;
    sta.push(r);
    insta[r] = 1;
    dfn[r] = low[r] = ++vid;
    ll s,t;
    for(ll i=head[r];i!=-1;i=E[i].next){
        s = E[i].to;
        if(!dfn[s]){
            tarjan(s,res,G);
            if(low[s] < low[r])low[r] = low[s];
        }else if(dfn[s] < low[r]&&insta[s]){
            low[r] = dfn[s];
        }
    }
    if(dfn[r] == low[r]){
        res.push_back(*(new vector<ll>()));
        do{
            t = sta.top(); sta.pop();
            insta[t] = 0;
            res.back().push_back(t);
            block[t] = res.size();
        }while(t != r);
    }
}
void mainTarjan(ll nodecon,vector<vector<ll>> &res,const graph &G){
    static bool first_time = 1;
    if(first_time){
        first_time = 0;
        dfn = new ll[G._maxn];
        low = new ll[G._maxn];
        insta = new ll[G._maxn];
        block = new ll[G._maxn];
    }
    memset(low,0,sizeof(ll)*G._maxn);
    memset(dfn,0,sizeof(ll)*G._maxn);
    vid = 0;
    for(ll i=1;i<=nodecon;i++){
        if(!dfn[i]){
            memset(insta,0,sizeof(ll)*G._maxn);
            tarjan(i,res,G);
        }
    }
}
