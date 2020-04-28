#ifndef DEFINE_BIT_HPP
#define DEFINE_BIT_HPP

#include <vector>
using namespace std;

namespace fenwick {
    using ll = long long;

    class Fenwick {
    public:
        int n;
        vector<ll> bit;

		Fenwick(int nn, ll init);
        ll sum(int i);
        void add(int i, ll x);
    };

    Fenwick::Fenwick(int n, ll init=0):n(n), bit(n + 1, init) {}

    ll Fenwick::sum(int i) {
        ll s = 0LL;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void Fenwick::add(int i, ll x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
}

#endif //DEFINE_BIT_HPP