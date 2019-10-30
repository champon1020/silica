#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from 
class BellmanFord {
    struct edge {
        int from, to, weight;
        edge(int f, int t, int w):from(f),to(t),weight(w){}
    };
    vector<edge> es;
    vector<ll> dist; // 最短距離
    int n; // 頂点数

    BellmanFord(int nn): n(nn){}

    function<void(int)> dfs = [&](int s){
        dist[s] = 0;
        for(auto const& e : es){
            if(dist[e.from] != inf && dist[e.to] > dist[e.from] + e.weight){
                dist[e.to] = dist[e.from] + e.weight;
                dfs(e.to);
            }
        }
    };

    void add(int f, int t, int w){
        es.push_back(edge(f, t, w));
    }

    void shortest(int s){
        dist.assign(n, inf);
        dfs(s);
    }

    bool shortest_nega(){
        dist.assign(n, 0);
        rep(i, n){
            for(auto const& e : es){
                if(dist[e.to] > dist[e.from] + e.weight){
                    dist[e.to] = dist[e.from] + e.weight;
                }
                if(i == n-1) return true;
            }
        }
        return false;
    }
};
// to


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
