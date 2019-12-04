#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


template<typename T>
class Dijkstra{
    struct edge {
        int to;
        T cost;
        edge(int t, T c) : to(t),cost(c){}
    };
    typedef pair<ll, int> P;
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
                if(dist[e.to] < dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    q.push(P(dist[e.to], e.to));
                }
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct span {
        int left;
        int right;
        ll cost;
        edge(int l, int r, ll c):left(l),right(r),cost(c){}
    };

    int n, m, l, r;
    ll c;
    cin >> n >> m;
    vector<span> e;
    rep(i, m){
        cin >> l >> r >> c;
        e.push_back(span(l, r, c));
    }

    

    return 0;
}