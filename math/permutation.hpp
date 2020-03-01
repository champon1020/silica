#ifndef DEFINE_PERMUTATION_HPP
#define DEFINE_PERMUTATION_HPP

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

namespace perm {

    using ll = long long;

    class Perm {
    public:
        int n;
        vector<int> p;
        vector<vector<int>> p_v;

        Perm(int n) : n(n) {}
        void build();
        void build_v();
    };

    void Perm::build() {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        do {
            ll num = 0;
            for (ll i = 0; i < v.size(); i++) num += pow(10, v.size() - (i + 1)) * v[i];
            p.push_back(num);
        } while (next_permutation(v.begin(), v.end()));
    }

    void Perm::build_v() {
        ll size = 1;
        for (ll i = 0; i <= n; i++) size *= i;
        p_v.assign(size);
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        ll ind = 0;
        do {
            for (auto const e : v) p_v[ind].push_back(e);
            ind++;
        } while (next_permutation(v.begin(), v.end()));
    }

}

#endif //DEFINE_PERMUTATION_HPP