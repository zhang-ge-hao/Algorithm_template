ll vid,*dfn,*low,*insta,*block;
stack<ll> sta;
void tarjan(ll r,ll f,vector<vector<ll>> &res,const graph &G,bool mode){
    ll *head = G.head,s,t;edge *E = G.E;
    bool haskip = 0;
    sta.push(r);
    insta[r] = 1,dfn[r] = low[r] = ++vid;
    for(ll i=head[r];i!=-1;i=E[i].next){
        s = E[i].to;
        if(s == f && mode && !haskip){
            haskip = 1; continue;
        }
        if(!dfn[s]){
            tarjan(s,r,res,G,mode);
            if(low[s] < low[r])low[r] = low[s];
        }else if(dfn[s] < low[r]&&insta[s])
            low[r] = dfn[s];
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
void mainTarjan(ll nodecon,vector<vector<ll>> &res,const graph &G,bool mode){
    // mode == 1 shuang lian tong mode == 0 qiang lian tong
    static bool first_time = 1;
    if(first_time){
        first_time = 0;
        dfn = new ll[G._maxn];
        low = new ll[G._maxn];
        insta = new ll[G._maxn];
        block = new ll[G._maxn];
    }
    ll arrsize = sizeof(ll)*(nodecon+1);
    memset(low,0,arrsize);
    memset(dfn,0,arrsize);
    vid = 0;
    for(ll i=1;i<=nodecon;i++){
        if(!dfn[i]){
            memset(insta,0,arrsize);
            tarjan(i,-1,res,G,mode);
        }
    }
}
