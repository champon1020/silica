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
        int get(long long k);
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

    int Fenwick::get(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)bit.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)bit.size() && bit[res + i] < k) {
                k = k - bit[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
}

#endif //DEFINE_BIT_HPP