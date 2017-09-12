#define MAXN 20007
#define MAXE 50007
struct edge{
    ll to,next;
    edge(ll a=0,ll b=0){
        to = a; next = b;
    }
}E[MAXE];
ll eid,head[MAXN];
void add(ll h,ll t){
    E[eid] = edge(t,head[h]);
    head[h] = eid++;
}

ll vid,dfn[MAXN],low[MAXN],insta[MAXN],block[MAXN];
stack<ll> sta;
void tarjan(ll r,vector<vector<ll>> &res){
    sta.push(r);
    insta[r] = 1;
    dfn[r] = low[r] = ++vid;
    ll s,t;
    for(ll i=head[r];i!=-1;i=E[i].next){
        s = E[i].to;
        if(!dfn[s]){
            tarjan(s,res);
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
void mainTarjan(ll nodecon,vector<vector<ll>> &res){
    memset(low,0,sizeof low);
    memset(dfn,0,sizeof dfn);
    vid = 0;
    for(ll i=1;i<=nodecon;i++){
        if(!dfn[i]){
            memset(insta,0,sizeof insta);
            tarjan(i,res);
        }
    }
}