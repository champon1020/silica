#ifndef DEFINE_SEGTREE_HPP
#define DEFINE_SEGTREE_HPP

#include <vector>
using namespace std;

namespace segtree {

    using ll = long long;
    const ll inf = 1e18;

    class RMaxQ {
    public:
        ll n;
        vector<ll> dat;

        explicit RMaxQ(int nn) {
			n = 1;
			while (n < nn) n *= 2;
			dat.resize(2 * n - 1, -inf);
		}

        void update(ll k, ll a);
        ll query(ll a, ll b, ll k, ll l, ll r);
        ll getquery(ll a, ll b);
        ll operator[](int i);
    };

    void RMaxQ::update(ll k, ll a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    ll RMaxQ::query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return -inf;
        if (a <= l && r <= b) return dat[k];
        else {
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

    ll RMaxQ::getquery(ll a, ll b) {
        return query(a, b, 0, 0, n - 1);
    }

    ll RMaxQ::operator[](int i) {
        return dat[i + n - 1];
    }

    // ------------------------------------------------------

	class RMinQ {
	public:
		ll n;
		vector<ll> dat;

		explicit RMinQ(int nn) {
			n = 1;
			while (n < nn) n *= 2;
			dat.resize(2 * n - 1, inf);
		}

		void update(ll k, ll a);
		ll query(ll a, ll b, ll k, ll l, ll r);
		ll getquery(ll a, ll b);
		ll operator[](int i);
	};

	void RMinQ::update(ll k, ll a) {
		k += n - 1;
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	ll RMinQ::query(ll a, ll b, ll k, ll l, ll r) {
		if (r <= a || b <= l) return inf;
		if (a <= l && r <= b) return dat[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}

	ll RMinQ::getquery(ll a, ll b) {
		return query(a, b, 0, 0, n - 1);
	}

	ll RMinQ::operator[](int i) {
		return dat[i + n - 1];
	}

}

#endif //DEFINE_SEGTREE_HPP