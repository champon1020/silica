#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define inf 1e18
using namespace std;


// from
template<typename T>
class Comb {
    ll mod = 1e9+7;
  public:
    vector<vector<T>> comb;
    vector<T> fact;
    vector<T> finv;
    vector<T> inv;
    Comb(int n){
        build(n);
    };

    void build(int n){
        inv.assign(n+1, 0);
        fact.assign(n+1, 0);
        finv.assign(n+1, 0);
        fact[0] = fact[1] = finv[0] = finv[1] = 1;
        inv[1] = 1;
        reps(i, 2, n){
            fact[i] = fact[i-1]*i % mod;
            inv[i] = mod - inv[mod%i]*(mod/i)%mod;
            finv[i] = finv[i-1]*inv[i]%mod;
        }
    }

    T result(int n, int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fact[n]*(finv[k]*finv[n-k]%mod)%mod;
    }
};
// to


// verify
// https://atcoder.jp/contests/abc034/tasks/abc034_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    cin >> w >> h;    
    ll mod = 1e9+7;
    int n = max(w, h);
    int k = min(w, h);

    Comb<ll> c;
    c.build(n+k);

    cout << c.result(n-1+k-1, k-1) << endl;

    return 0; 
}
