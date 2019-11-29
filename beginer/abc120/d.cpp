#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
#define enl << endl
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};



const int MAX = 100010;

class UnionFind {
public:
    ll par[MAX];
    ll num[MAX];

    UnionFind(int n){
        rep(i, n){
            par[i] = i;
            num[i] = 1;
        }
    }

    ll find(ll x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        par[x] = y;
        num[y] += num[x];
    }

    bool same(ll x, ll y){
        return find(x) == find(y);
    }

    ll size(ll x){
        return num[find(x)];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    vector<pair<ll, ll>> ab;
    vector<ll> res;
    cin >> n >> m;

    ll a, b;
    rep(i, m){
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }

    UnionFind tree(n+1);
    res.push_back(n*(n-1)/2);
    repr(i, m-1, 0){
        ll aa = ab[i].first;
        ll bb = ab[i].second;
        auto last = res.back();

        if(tree.same(aa, bb)){
            res.push_back(last);
        }else{
            res.push_back(last - tree.size(aa)*tree.size(bb));
        }
        //cout << tree.size(aa) sp tree.size(bb) << endl;
        tree.unite(aa, bb);
    }

    repr(i, res.size()-2, 0){
        cout << res[i] << endl;
    }

    return 0;
}
