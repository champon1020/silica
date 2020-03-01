#ifndef DEFINE_BELLMANFORD_HPP
#define DEFINE_BELLMANFORD_HPP

#include <vector>
using namespace std;

namespace bellman {

    using ll = long long;
    const ll inf = 5e18;

    class BellmanFord {
    private:
        struct edge {
            int from, to;
            ll cost;
            edge(int f, int t, ll c) : from(f), to(t), cost(c) {}
        };
    public:
        vector<edge> es;
        vector<ll> dist; // min distance
        int n;  // num of nodes
        bool negative = false;

        BellmanFord(int n) : n(n) {}
        void add(int from, int to, ll cost);
        void build(int s);
    };

    void BellmanFord::add(int from, int to, ll cost) {
        es.push_back(edge(from, to, cost));
    }

    void BellmanFord::build(int s) {
        dist.assign(n, inf);
        dist[s] = 0;
        int cnt = 1;
        while (true) {
            bool update = false;
            for (auto const &e : es) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                    update = true;
                }
            }
            cnt++;
            if (cnt == n && update) {
                negative = true;
                break;
            }
            if (!update) break;
        }
    }

}

// example
// https://atcoder.jp/contests/abc061/tasks/abc061_d


#endif //DEFINE_BELLMANFORD_HPP