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
        void build(int v);
    };

    void Perm::build(int initv = 1) {
        vector<int> v(n);
        iota(v.begin(), v.end(), initv);
        do {
            ll num = 0;
            for(int i=0; i<v.size(); i++){
                // some process
            }
            p.push_back(num);
        } while (next_permutation(v.begin(), v.end()));
    }

}

#endif //DEFINE_PERMUTATION_HPP