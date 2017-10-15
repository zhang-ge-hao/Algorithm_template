bool spfa(ll sta,ll *d,ll nodecon,graph G){
    memset(d,INF,sizeof(ll)*G._maxn);
    ll *head = G.head; edge *E = G.E;
    queue<ll> que; que.push(sta);
    static bool *in = new bool[G._maxn];
    memset(in,0,sizeof(bool)*G._maxn);
    static ll *times = new ll[G._maxn];
    memset(times,0,sizeof(ll)*G._maxn);
    d[sta] = 0; in[sta] = 1; times[sta] = 1;
    while(!que.empty()){
        ll f = que.front();que.pop();
        in[f] = 0;
        for(ll i=head[f];i!=-1;i=E[i].next){
            ll s = E[i].to;
            if(d[f]+E[i].len < d[s]){
                d[s] = d[f]+E[i].len;
                if(!in[s]){
                    in[s] = 1;
                    times[s] ++;
                    if(times[s] > nodecon)return 0;
                    que.push(s);
                }
            }
        }
    }
    return 1;
}
