#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from 
class Bit{
  public:
    ll n;
    vector<ll> bit;

    Bit(ll nn, ll e): n(nn),bit(nn+1, e){};

    ll sum(ll i) {
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i&-i;
        }
        return s;
    }

    void add(ll i, ll x){
        while(i <= n){
            bit[i] += x;
            i += i&-i;
        }
    }
};
// to


int main(){
    
}
