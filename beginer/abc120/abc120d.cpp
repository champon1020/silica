#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
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
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int cnt = 0;
int visit[100010];
vector<int> g[100010];

void visitinit(ll n){
    rep(i, n){
        visit[i] = 0;
    }
}

void dfs(int u){
    cnt++;
    visit[u] = 1;
    for(auto gg : g[u]){
        if(visit[gg] == 1) continue;
        if(gg == -1) continue;
        dfs(gg);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a, b;
    vector<pair<ll, ll>> bridge;
    cin >> n >> m;
    rep(i, m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        bridge.push_back(make_pair(a, b));
    }

    rep(i, m){
        cnt = 0;
        visitinit(n);
        ll island1 = bridge[i].first;
        ll island2 = bridge[i].second;
        g[island1][island2] = -1;
        g[island2][island1] = -1;
        
    }

    return 0;
}