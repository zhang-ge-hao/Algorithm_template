#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define ppi pair<pii,ll>
#define pip pair<ll,pii>
#define  l first
#define  r second


//-------------------IO
ll read() {
    bool flag = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') flag = true; else result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result * 10 + (ch - '0');
    }
    if (flag)return -result;
    else return result;
}
//-------------------IO

//-------------------DEBUG
ostream &operator<<(ostream &o, pii xx) {
    o << "(" << xx.first << "," << xx.second << ")";
    return o;
}

#define debug(xx) cout<<"{"<<(#xx)<<":"<<xx<<"}"
#define debug_array(xx, beg, end)cout<<#xx<<":{";\
for(int _i##xx=beg;_i##xx<end;_i##xx++){cout<<xx[_i##xx]<<" ";}\
cout<<"}"<<endl
//-------------------DEBUG