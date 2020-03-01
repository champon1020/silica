#ifndef DEFINE_BIT_HPP
#define DEFINE_BIT_HPP

#include <vector>
using namespace std;

namespace bit {

    using ll = long long;

    class Bit {
    public:
        ll n;
        vector<ll> bit;

        Bit(ll nn, ll e);
        ll sum(ll i);
        void add(ll i, ll x);
    };

    Bit::Bit(ll nn, ll e):n(nn), bit(nn + 1, e) {}

    ll Bit::sum(ll i) {
        ll s = 0LL;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void Bit::add(ll i, ll x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

}

#endif //DEFINE_BIT_HPP