#include "basic.h"
template<class _type>struct LIS{
    static bool comp(const _type &a,const _type &b){
        return a <= b;
    }
    ll getLisCon(_type *arr,ll len){
        _type l[len],*_t,*_end = l;
        for(ll i=0;i<len;i++){
            _t = lower_bound(l,_end,arr[i],LIS::comp);
            if(_t == _end)_end ++;
            *_t = arr[i];
        }
        return _end - l;
    }
};
