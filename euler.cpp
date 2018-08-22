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



//欧拉函数打表 速度最快，空间消耗大一些 
const ll MAXN=2e7;
ll euler[MAXN],sum[MAXN];
bool is_prime[MAXN];
int prime[MAXN];
ll p_cnt;


void euler3(){
	for (int i=1; i<MAXN; ++i) euler[i]=i;
    p_cnt=0;
    sum[0]=0;
    for (int i=2; i<MAXN; ++i) {
        if (!is_prime[i]) {
            prime[p_cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; j < p_cnt && prime[j] * i < MAXN; ++j) {
            is_prime[prime[j] * i] = true;
            if (i % prime[j] == 0) {
                euler[i * prime[j]] = euler[i] * prime[j];   //条件2的递推
                break;            //为啥break?拿3,5,7,15,35,105动手推一下，这里确保每个数只
            } else {
                euler[i * prime[j]] = euler[i] * (prime[j] - 1); //条件3的递推
            }
        }
    }
}