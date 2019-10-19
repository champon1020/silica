#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


struct Node {
    int to;
    ll w;
    Node(int to_, ll w_){
        to = to_;
        w = w_;
    }
};

vector<Node> g[100010];
set<int> visited;
ll l;
int goal;

int dfs(int u, ll cnt, ll gas){
    visited.insert(u);

    //cout << u << " " << cnt << endl;
    if(u == goal) return cnt;

    for(auto gg : g[u]){
        if(visited.find(gg.to) != visited.end()) continue;
        int res;
        if(gas - gg.w < 0){
            res = dfs(gg.to, cnt+1, l-gg.w);
        }else{
            gas -= gg.w;
            res = dfs(gg.to, cnt, gas);
        }
        if(res != -1) return res;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a, b, c;
    cin >> n >> m >> l;
    rep(i, m){
        cin >> a >> b >> c;
        g[a].push_back(Node(b, c));
        g[b].push_back(Node(a, c));
    }
    
    int q, s, t;
    cin >> q;
    rep(i, q){
        visited.clear();
        cin >> s >> t;
        goal = t;
        int res = dfs(s, 0, l);
        cout << res << endl;
    }

    return 0;
}
