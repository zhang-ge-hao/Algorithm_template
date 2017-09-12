template<typename _type>struct KMP{
    _type P[MAXN],T[MAXN];
    ll lenP,lenT;
    ll *build_next(){
        ll j = 0,*N = new ll[lenP+1];
        ll t = N[0] = -1;
        while(j < lenP){
            if(0>t || P[j]==P[t]){
                j++; t++;
                //N[j] = (P[j]!=P[t]?t:N[t]);
                N[j] = t;
            }else t = N[t];
        }
        return N;
    }
    ll Match(ll r = 0){
        ll *Next = build_next();
        ll i=0,j=0;
        _type *TT = T+r; lenT -= r;
        while(j<lenP && i<lenT){
            if(0>j || TT[i]==P[j]){
                i++; j++;
            }else j = Next[j];
        }
        lenT += r;
        delete[]Next;
        return i-j+r;
    }
};