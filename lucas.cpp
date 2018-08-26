#include "basic.h"

ll quick_mod(ll a, ll b){
    ll ans = 1;
    a %= MOD;
    while(b){
        if(b & 1){
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a*a%MOD;
    }
    return ans;
}
ll C(ll n, ll m){
    if(m > n)return 0;
    ll ans = 1;
    for(int i=1;i<=m;i++){
        ll a = (n+i-m)%MOD;
        ll b = i%MOD;
        ans = ans*(a*quick_mod(b,MOD-2)%MOD)%MOD;
    }
    return ans;
}
ll Lucas(ll n, ll m){
    if(m == 0) return 1;
    return C(n%MOD,m%MOD)*Lucas(n/MOD,m/MOD)%MOD;
}

ll fact[100005];
void init(){
    fact[0]=1;
    for(ll i=1;i<=MOD;i++)
        fact[i]=fact[i-1]*i%MOD;
}
ll pow_m(ll a,ll k,ll p){
    ll ans=1;
    ll tmp=a%p;
    while(k){
        if(k&1)ans=ans*tmp%p;
        tmp=tmp*tmp%p;
        k>>=1;
    }
    return ans;
}
ll C2(ll n,ll m,ll p){
    if(m>n)return 0;
    return fact[n]*pow_m(fact[m]*fact[n-m]%p,p-2,p);
}
ll Lucas(ll n,ll m,ll p){
    ll ans=1;
    while(n&&m){
        ans=ans*C2(n%p,m%p,p)%p;
        n/=p;
        m/=p;
    }
    return ans;
}
