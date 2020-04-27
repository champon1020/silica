#ifndef DEFINE_BIT_HPP
#define DEFINE_BIT_HPP

#include <vector>
using namespace std;

namespace fenwick {

    using ll = long long;

    class Fenwick {
    public:
        ll n;
        vector<ll> bit;

		Fenwick(ll nn, ll e);
        ll sum(ll i);
        void add(ll i, ll x);
    };

    Fenwick::Fenwick(ll nn, ll e):n(nn), bit(nn + 1, e) {}

    ll Fenwick::sum(ll i) {
        ll s = 0LL;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void Fenwick::add(ll i, ll x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

}

#endif //DEFINE_BIT_HPP