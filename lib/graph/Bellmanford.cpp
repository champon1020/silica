#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<e; i++)
#define inf 1e18
using namespace std;


// from 
template<typename T>
class BellmanFord {
    struct edge {
        int from, to;
        T cost;
        edge(int f, int t, T c) : from(f),to(t),cost(c){}
    };
  public:
    vector<edge> es;
    vector<ll> dist; // minimum distance
    int n; // num of nodes
    bool negative = false;
    BellmanFord(int nn): n(nn){}

    void add(int f, int t, T c){
        es.push_back(edge(f, t, c));
    }

    void build(int s){
        dist.assign(n+1, inf);
        dist[s] = 0;
        int cnt = 1;
        while(true){
            bool update = false;
            for(auto const& e : es){
                if(dist[e.from] != inf && dist[e.to] > dist[e.from] + e.weight){
                    dist[e.to] = dist[e.from] + e.weight;
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
};
// to


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
// example
// https://atcoder.jp/contests/abc061/tasks/abc061_d
