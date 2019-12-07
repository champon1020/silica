#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, n) for(ll i=n; i>=0; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define ok cout << "ok" << endl
#define sp << " " <<
using namespace std;


//from
template<typename T>
class WarshallFloyd {
public:
    int n;
    vector<vector<T>> g;
    WarshallFloyd(int n, T mx):n(n){
        g.assign(n+1, vector<T>(n+1, mx));
        reps(i, 0, n){
            g[i][i] = 0;
        }
    }

    void add(int from, int to, ll cost){
        g[from][to] = cost;
    }

    void build(){
        reps(k, 1, n){
            reps(i, 1, n){
                reps(j, 1, n){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    T result(int from, int to){
        return g[from][to];
    }
};
// to


// https://atcoder.jp/contests/abc012/tasks/abc012_4
int main(){
    int n, m;
    int a, b, t;
    cin >> n >> m;
    WarshallFloyd<ll> wf(n, inf);
    rep(i, m){
        cin >> a >> b >> t;
        wf.add(a, b, t);
        wf.add(b, a, t);
    }

    wf.build();

    ll res = inf;
    reps(i, 1, n){
        ll mx = 0;
        reps(j, 1, n){
            mx = max(mx, wf.result(i, j));
        }
        res = min(res, mx);
    }

    cout << res << endl;
}