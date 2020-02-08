#ifndef DEFINE_COMBINATION_HPP
#define DEFINE_COMBINATION_HPP

#include <vector>
using namespace std;

template<typename T>
class Comb
{
    typedef long long ll;
    ll mod = 1e9+7;
  public:
    vector<vector<T>> comb;
    vector<T> fact;
    vector<T> finv;
    vector<T> inv;
    Comb(){};

    void build(int n);
    T result(int n, int k); // return nCk
};

#endif //DEFINE_COMBINATION_HPP

template<typename T>
void Comb<T>::build(int n)
{
    inv.assign(n+1, 0);
    fact.assign(n+1, 0);
    finv.assign(n+1, 0);
    fact[0] = fact[1] = finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<=n; i++){
        fact[i] = fact[i-1]*i % mod;
        inv[i] = mod - inv[mod%i]*(mod/i)%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

template<typename T>
T Comb<T>::result(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fact[n]*(finv[k]*finv[n-k]%mod)%mod;
}

// verify
// https://atcoder.jp/contests/abc034/tasks/abc034_c
