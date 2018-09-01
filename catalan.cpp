#include "basic.h"

ll a[105][105],b[105];
void catalan(ll N){
    ll len,carry,temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for(ll i=2;i<=N;i++){
        for(ll j=0;j<len;j++)
            a[i][j] = a[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(ll j=0;j<len;j++){
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry){
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(ll j=len-1;j>=0;j--){
            temp = carry*10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
            }
        while(!a[i][len-1])len --;
        b[i] = len;
    }
}
