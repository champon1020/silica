#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from
class SegmentTree {
  public:
    ll n;
    vector<ll> dat;

    void init(ll nn){
        n = 1;
        while(n < nn) n*=2;
        dat.resize(2*n-1, inf);
    }

    void update(ll k, ll a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
        }
    }

    ll query(ll a, ll b, ll k, ll l, ll r){
        if(r <= a || b <= l) return inf;
        if(a <= l && r <= b) return dat[k];
        else{
            ll vl = query(a, b, k*2+1, l, (l+r)/2);
            ll vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }

    ll operator[](int i){
        return dat[i + n - 1];
    }
};
// to


int main() {
    
}
