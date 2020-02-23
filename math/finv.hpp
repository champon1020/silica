#ifndef INCLUDE_FINV_HPP
#define INCLUDE_FINV_HPP

#include <vector>
using namespace std;

namespace finv {

    using ll = long long;
    ll mod = 1e9 + 7;

    template<typename T>
    class Finv {
    public:
        vector<T> fact;
        vector<T> finv;
        vector<T> inv;

        Finv(ll n) { build(n); }
        void build(ll n);
    };

    template<typename T>
    void Finv<T>::build(ll n) {
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

}

#endif //INCLUDE_FINV_HPP
