//
// Created by champon1020 on 2020/04/11.
//

#ifndef INCLUDE_KRUSKAL_HPP

#include <vector>
#include <algorithm>
using namespace std;

namespace kruskal {

    using ll = long long;

    class Kruskal {
        struct edge {
            int u, v;
            ll cost;
            edge(int u, int v, ll cost):u(u), v(v), cost(cost){};
        };

        // >>> simple unionfind
        vector<ll> par;
        void init_uf(int n) {
            par.assign(n, 0);
            for(int i=0; i<n; i++){
                par[i] = i;
            }
        }

        ll find(ll x){
            if(par[x] == x) return x;
            else return par[x] = find(par[x]);
        }

        void unite(ll x, ll y){
            x = find(x);
            y = find(y);
            if(x == y) return;
            par[x] = y;
        }

        bool same(ll x, ll y){
            return find(x) == find(y);
        }
        // <<< unionfind

        static bool comp(const edge& e1, const edge& e2) {
            return e1.cost < e2.cost;
        }

    public:
        vector<edge> es;
        int v, e;   // n: 頂点数, e: 辺数
        Kruskal();
        Kruskal(int v, int e):v(v), e(e){};
        void add(int u, int v, ll cost);
        ll compute();
    };

    void Kruskal::add(int u, int v, ll cost) {
        es.emplace_back(u, v, cost);
    }

    ll Kruskal::compute() {
        sort(es.begin(), es.end(), comp);
        init_uf(v);
        ll res = 0;
        for(auto ee : es){
            if(!same(ee.u, ee.v)){
                unite(ee.u, ee.v);
                res += ee.cost;
            }
        }
        return res;
    }
}

#define INCLUDE_KRUSKAL_HPP

#endif //INCLUDE_KRUSKAL_HPP


// verify
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A