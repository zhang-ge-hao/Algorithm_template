void euler1(ll *euler,ll _n){
	memset(euler,0,sizeof(ll)*_n);
	for(ll i=1;i<=_n;i++)euler[i] = i;
	for(ll i=2;i<=_n;i++)
	if(euler[i] == i)
		for(ll j=i;j<=_n;j+=i)
			euler[j] = euler[j]/i*(i-1);
}
ll euler2(ll n){
	ll res=n,a=n;
	for(ll i=2;i*i<=a;i++){
		if(a%i==0){
			res=res/i*(i-1);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) res=res/a*(a-1);
	return res;
}
