#ifndef DEFINE_DIJKSTRA_HPP
#define DEFINE_DIJKSTRA_HPP

#include <vector>
#include <queue>
using namespace std;

template<typename T>
class Dijkstra
{
    typedef long long ll;
    const ll inf = 4e18;
    struct edge {
        int to;
        T cost;
        edge(int t, T c) : to(t),cost(c){}
    };
    typedef pair<T, int> P;
public:
    int n;
    vector<edge> g[100010];
    vector<ll> dist;
    Dijkstra(int n): n(n){};

    void add(int from, int to, T cost);
    void build(int s);
    T result(int s);
};

#endif  //DEFINE_DIJKSTRA_HPP

template<typename T>
void Dijkstra<T>::add(int from, int to, T cost)
{
    g[from].push_back(edge(to, cost));
}

template<typename T>
void Dijkstra<T>::build(int s)
{
    priority_queue<P, vector<P>, greater<P>> q;
    dist.assign(n, inf);
    dist[s] = 0;
    q.push(P(0, s));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto const& e : g[v]) {
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                q.push(P(dist[e.to], e.to));
            }
        }
    }
}

template<typename T>
T Dijkstra<T>::result(int s)
{
    return dist[s];
}

// verify
// https://atcoder.jp/contests/abc070/tasks/abc070_d
