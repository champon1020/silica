#ifndef DEFINE_SEGTREE_HPP
#define DEFINE_SEGTREE_HPP

#include <vector>
using namespace std;

namespace segtree {

    using ll = long long;
    const ll inf = 1e18;

	class SegTree {
	public:
		ll n;
		vector<ll> dat;

		explicit SegTree(int N) {
			n = 1;
			while (n < N) n *= 2;
			dat.resize(2 * n - 1, inf);
		}

		void update(int k, ll a);
		ll rmq(int a, int b, int k, int l, int r);
		ll query(int a, int b);
		ll get(int k);
	};

	void SegTree::update(int k, ll a) {
		k += n - 1;
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	ll SegTree::rmq(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return inf;
		if (a <= l && r <= b) return dat[k];
		else {
			ll vl = rmq(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = rmq(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}

	ll SegTree::query(int a, int b) {
		return rmq(a, b, 0, 0, n - 1);
	}

	ll SegTree::get(int k) {
	    return dat[k+n-1];
	}

}

#endif //DEFINE_SEGTREE_HPP