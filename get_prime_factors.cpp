#include "basic.h"
ll get_prime_factors(ll _n,ll *res){//res�лᱻ�����������
    ll n2 = _n,rid = 0;
    if(_n<2)return 0;
    for(ll i=2;i*i<=n2;i++)if(n2%i == 0){
        while(n2%i==0)n2=n2/i;
        res[rid++] = i;
    }
    if(n2!=1)res[rid++] = n2;
    return rid; //��������Ŀ
}
