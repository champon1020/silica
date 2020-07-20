#ifndef DEFINE_COMBINATION_HPP
#define DEFINE_COMBINATION_HPP

#include <vector>
using namespace std;

namespace comb {

using ll = long long;

class Comb {
private:
  ll mod;

  ll powm(ll a, ll b) {
    ll res = 1;
    while(b > 0){
      if(b & 1) (res *= a) %= mod;
      (a *= a) %= mod;
      b >>= 1;
    }
    return res;
  }

public:
  vector<ll> fact;
  vector<ll> finv;
  vector<ll> inv;

  Comb(ll mod = 1e9+7):mod(mod) {};
  Comb(int n, ll mod = 1e9+7):mod(mod) { build(n); }
  void build(int n);
  ll res(int n, int k); // return nCk
  ll resone(ll n, ll k);
  ll resp(int n, int k);
  ll resh(int n, int k);
};

void Comb::build(int n) {
  inv.assign(n + 1, 0);
  fact.assign(n + 1, 0);
  finv.assign(n + 1, 0);
  fact[0] = fact[1] = finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    finv[i] = finv[i - 1] * inv[i] % mod;
  }
}

ll Comb::res(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * (finv[k] * finv[n - k] % mod) % mod;
}

ll Comb::resone(ll n, ll k) {
  ll res = 1;
  for (ll i = 0; i < k; i++) {
    (res *= (n-i)) %= mod;
    (res *= this->powm(i+1, mod-2)) %= mod;
  }
  return res;
}

ll Comb::resp(int n, int k) {
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fact[n] * finv[n - k] % mod;
}

ll Comb::resh(int n, int k) {
  return res(n+k-1, k);
}

}

#endif //DEFINE_COMBINATION_HPP


// verify
// https://atcoder.jp/contests/abc034/tasks/abc034_c
