#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from
template<typename T>
class Dijkstra{
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
    Dijkstra(int nn): n(nn){};

    void add(int f, int t, T c){
        g[f].push_back(edge(t, c));
    }

    void build(int s) {
        priority_queue<P, vector<P>, greater<P>> q;
        dist.assign(n+1, inf);
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

    T result(int s){
        return dist[s];
    }
};
// to


// verify
// https://atcoder.jp/contests/abc070/tasks/abc070_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    ll c;
    cin >> n;
    Dijkstra<ll> dk(n);
    rep(i, n-1){
        cin >> a >> b >> c;
        dk.add(a, b, c);
        dk.add(b, a, c);
    }
    int q, k, x, y;
    cin >> q >> k;
    dk.build(k);
    rep(i, q){
        cin >> x >> y;
        cout << dk.result(x) + dk.result(y) << endl;
    }
    return 0;
}
