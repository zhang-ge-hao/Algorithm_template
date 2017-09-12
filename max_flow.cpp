ll n,flow[MAXN][MAXN],pre[MAXN],use[MAXN];
bool bfs(){
    queue<ll> que; que.push(1);
    ll tn;
    memset(pre,0,sizeof pre);
    memset(use,0,sizeof use);
    while(!que.empty()){
        tn = que.front(); que.pop();
        if(tn == n)return 1;
        for(ll i=1;i<=n;i++){
            if(!use[i] && flow[tn][i]){
                use[i] = 1;
                pre[i] = tn;
                que.push(i);
            }
        }
    }
    return 0;
}
ll max_flow(){
    ll minf,res = 0;
    while(bfs()){
        minf = 1e9;
        for(ll i=n;i!=1;i=pre[i])
            minf = min(minf,flow[pre[i]][i]);
        for(ll i=n;i!=1;i=pre[i]){
            flow[pre[i]][i] -= minf;
            flow[i][pre[i]] += minf;
        }
        res += minf;
    }
    return res;
}