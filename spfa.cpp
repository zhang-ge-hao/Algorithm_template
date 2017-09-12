void spfa(ll sta,ll *d){
    memset(d,INF,sizeof(ll)*(MAXN));
    d[sta] = 0;
    queue<ll> que; que.push(sta);
    bool in[MAXN]; memset(in,0,sizeof in);
    while(!que.empty()){
        ll f = que.front();que.pop();
        in[f] = 0;
        for(ll i=head[f];i!=-1;i=E[i].next){
            ll s = E[i].to;
            if(d[f]+E[i].len < d[s]){
                d[s] = d[f]+E[i].len;
                if(!in[s]){
                    in[s] = 1;
                    que.push(s);
                }
            }
        }
    }
}