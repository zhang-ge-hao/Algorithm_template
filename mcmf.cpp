struct MCMF{
    ll n,m;
    struct Edge{
        ll from, to, cap, flow, cost;
        Edge(ll a,ll b,ll c,ll d,ll e){
            from = a;to = b;cap = c;flow = d;cost = e;
        }
    };
    vector<Edge> edge;
    vector<ll> g[MAXN];
    bool inq[MAXN];
    ll d[MAXN],p[MAXN],a[MAXN];
    void init(ll n){
        this->n = n;
        for(ll i=1;i<=n;i++)g[i].clear();
        edge.clear();
    }
    void add_edge(ll from,ll to,ll cap,ll cost){
        edge.push_back(Edge(from,to,cap,0,cost));
        edge.push_back(Edge(to,from,0,0,-cost));
        m = edge.size();
        g[from].push_back(m-2);
        g[to].push_back(m-1);
    }
    bool spfa(ll s,ll t,ll& flow,ll& cost){
        memset(d,0x3f,sizeof d);
        memset(inq,0,sizeof inq);
        d[s] = 0, inq[s] = true, p[s] = 0, a[s] = INF;
        queue<ll> q;
        q.push(s);
        while(!q.empty()){
            ll u = q.front();q.pop();
            inq[u] = false;
            ll sz = g[u].size();
            for(ll i=0;i<sz;i++){
                Edge& e = edge[g[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u]+e.cost){
                    d[e.to] = d[u]+e.cost;
                    p[e.to] = g[u][i];
                    a[e.to] = min(a[u], e.cap-e.flow);
                    if(!inq[e.to]) q.push(e.to), inq[e.to] = true;
                }
            }
        }
        if(INF == d[t]) return false;
        flow += a[t];
        cost += (ll)d[t]*(ll)a[t];
        for(ll u = t; u != s; u = edge[p[u]].from){
            edge[p[u]].flow += a[t];
            edge[p[u]^1].flow -= a[t];
        }
        return true;
    }
    ll mincostmaxflow(ll s, ll t, ll & cost){
        ll flow = 0;
        cost = 0;
        while(spfa(s,t,flow,cost));
        return flow;
    }
}mcmf;
