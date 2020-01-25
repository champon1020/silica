#ifndef DEFINE_BELLMANFORD_HPP
#define DEFINE_BELLMANFORD_HPP

template<typename T>
class BellmanFord
{
    struct edge{
        int from, to;
        T cost;
        edge(int f, int t, T c) : from(f),to(t),cost(c){}
    };
public:
    vector<edge> es;
    vector<ll> dist; // min distance
    int n;  // num of nodes
    bool negative = false;
    BellmanFord(int n): n(n){}

    void add(int from, int to, T cost);
    void build(int s);
};

#endif //DEFINE_BELLMANFORD_HPP

template<typename T>
void BellmanFord<T>::add(int from, int to, T cost)
{
    es.push_back(edge(from, to, cost));
}

template<typename T>
void BellmanFord<T>::build(int s)
{
    dist.assign(n, inf);
    dist[s] = 0;
    int cnt = 1;
    while(true){
        bool update = false;
        for(auto const& e : es){
            if(dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                update = true;
            }
        }
        cnt++;
        if(cnt == n && update){
            negative = true;
            break;
        }
        if(!update) break;
    }
}

// example
// https://atcoder.jp/contests/abc061/tasks/abc061_d
