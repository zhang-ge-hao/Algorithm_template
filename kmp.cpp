template<typename _type>struct KMP{
    _type *P; ll lenP,*next = 0;
    void build_next(){
        ll j = 0;
        next = new ll[lenP+1];
        ll t = next[0] = -1;
        while(j < lenP){
            if(0>t || P[j]==P[t]){
                j++; t++;
                next[j] = (P[j]!=P[t]?t:next[t]);
                //next[j] = t;
            }else t = next[t];
        }
    }
    void setP(_type *_P,ll _lenP){
        if(next)delete[]next;
        P = _P; lenP = _lenP;
        build_next();
    }
    ll match(_type *T,ll lenT,ll r = 0){
        build_next();
        ll i=0,j=0;
        _type *TT = T+r; lenT -= r;
        while(j<lenP && i<lenT){
            if(0>j || TT[i]==P[j]){
                i++; j++;
            }else j = next[j];
        }
        lenT += r;
        return i-j+r;
    }
};
