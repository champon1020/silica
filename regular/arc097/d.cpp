#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
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


const int MAXN = 100010;

class UnionFind {
    int par[MAXN];
    int rank[MAXN];

public:
    UnionFind(int n){
        rep(i, n){
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y, tmp;
    vector<int> p;
    vector<pair<int, int>> xy;
    p.push_back(0);

    cin >> n >> m;
    rep(i, n){
        cin >> tmp;
        p.push_back(tmp);
    }
    rep(i, m){
        cin >> x >> y;
        xy.push_back(make_pair(x, y));
    }

    UnionFind tree(n+1);
    for(auto e : xy){
        tree.unite(e.first, e.second);
    }

    ll res = 0;
    reps(i, 1, n+1){
        if(p[i] == i){
            res++;
        }else if(tree.same(i, p[i])){
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
