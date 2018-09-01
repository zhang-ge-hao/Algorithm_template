#include "basic.h"

#define BM_TYPE char
struct BM{
    const static int MAXC = 26,CHAR0 = 'a';
    ll *bc = 0,*ss = 0,*gs = 0,sizeP = 0;
    BM_TYPE *P = 0;
    void buildBC(){
        bc = new ll[MAXC];
        for(ll j=0;j<MAXC;j++)bc[j] = -1;
        for(ll j=0;j<sizeP;j++)bc[P[j]-CHAR0] = j;
    }
    void buildSS(){
        ss = new ll[sizeP];
        ss[sizeP-1] = sizeP;
        for(ll lo=sizeP-1,hi=sizeP-1,j=lo-1;j>=0;j--){
            if((lo<j) && (ss[sizeP-hi+j-1]<=j-lo))
                ss[j] = ss[sizeP-hi+j-1];
            else{
                hi = j; lo = min(lo,hi);
                while((0<=lo) && (P[lo]==P[sizeP-hi+lo-1]))
                    lo--;
                ss[j] = hi-lo;
            }
        }
    }
    void buildGS(){
        gs = new ll[sizeP];
        for(ll j=0;j<sizeP;j++)gs[j] = sizeP;
        for(ll i=0,j=sizeP-1;j>=0;j--)
            if(j+1 == ss[j])
                while(i < sizeP-j-1)
                    gs[i++] = sizeP-j-1;
        for(ll j=0;j<sizeP-1;j++)
            gs[sizeP-ss[j]-1] = sizeP-j-1;
    }
    void setP(BM_TYPE *_P,ll _sizeP){
        if(bc)delete []bc;
        if(gs)delete []gs;
        if(ss)delete []ss;
        P = _P; sizeP = _sizeP;
        buildBC(); buildSS(); buildGS();
    }
    ll match(const BM_TYPE *T,ll sizeT){
        ll i = 0;
        while(sizeT >= i+sizeP){
            ll j = sizeP-1;
            while(P[j] == T[i+j])
                if(0 > --j)break;
            if(0 > j)break;
            else i += max(gs[j],j-bc[T[i+j]-CHAR0]);
        }
        return i;
    }
};
