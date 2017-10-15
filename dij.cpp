#define INF 0x3f3f3f3f
void dij(ll sta,ll *d,graph G){
    ll *head = G.head; edge *E = G.E;
    memset(d,INF,sizeof(ll)*G._maxn);
    d[sta] = 0;
    priority_queue<P2,vector<P2>,greater<P2> >que;
    que.push(P2(0,sta));
    ll t,s,p,l;
    while(!que.empty()){
        t = que.top().second; p = que.top().first;
        que.pop();
        if(p > d[t])continue;
        for(ll i=head[t];i!=-1;i=E[i].next){
            s = E[i].to; l = E[i].len;
            if(p+l < d[s]){
                d[s] = p+l;
                que.push(P2(d[s],s));
            }
        }
    }
}
