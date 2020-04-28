#ifndef DEFINE_WARSHALLFLOYD_HPP
#define DEFINE_WARSHALLFLOYD_HPP

#include <vector>
using namespace std;

namespace warshall {

    using ll = long long;
    const ll inf = 1e18;

    class WarshallFloyd {
    public:
        int n;
        bool negative = false;
        vector<vector<ll>> g;

        explicit WarshallFloyd(int n);
        void add(int from, int to, ll cost);
        void build();
        ll res(int from, int to);
        bool isNegative() const;
    };

    WarshallFloyd::WarshallFloyd(int n) : n(n) {
        g.assign(n, vector<ll>(n, inf));
        for (int i = 0; i < n; i++) {
            g[i][i] = 0;
        }
    }

    void WarshallFloyd::add(int from, int to, ll cost) {
        g[from][to] = cost;
    }

    void WarshallFloyd::build() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(g[i][k] == inf || g[k][j] == inf) continue;
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
                if(g[i][i] < 0) {
                    negative = true;
                    return;
                }
            }
        }
    }

    ll WarshallFloyd::res(int from, int to) {
        return g[from][to];
    }

    bool WarshallFloyd::isNegative() const {
        return negative;
    }

}

// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4

#endif //DEFINE_WARSHALLFLOYD_HPP