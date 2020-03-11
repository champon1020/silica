#ifndef DEFINE_DIJKSTRA_HPP
#define DEFINE_DIJKSTRA_HPP

#include <vector>
#include <queue>
using namespace std;

namespace dijkstra {

    using ll = long long;
    const ll inf = 1e18;

    class Dijkstra {
    private:
        struct edge {
            int to;
            ll cost;
            edge(int t, ll c) : to(t), cost(c) {}
        };
        typedef pair<ll, int> P;
    public:
        int n;
        vector<edge> g[100010];
        vector<ll> dist;

        Dijkstra(int n) : n(n) {};
        void add(int from, int to, ll cost);
        void build(int s);
        ll result(int s);
    };

    void Dijkstra::add(int from, int to, ll cost) {
        g[from].push_back(edge(to, cost));
    }

    void Dijkstra::build(int s) {
        priority_queue<P, vector<P>, greater<P>> q;
        dist.assign(n, inf);
        dist[s] = 0;
        q.push(P(0, s));
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (auto const &e : g[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    q.push(P(dist[e.to], e.to));
                }
            }
        }
    }

    ll Dijkstra::result(int s) {
        return dist[s];
    }

}

// verify
// https://atcoder.jp/contests/abc070/tasks/abc070_d

#endif  //DEFINE_DIJKSTRA_HPP