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
class UnionFind{
  public:
    vector<T> par;
    vector<T> rank;
    vector<T> size;
    UnionFind(int n) : par(n+1, 0),rank(n+1, 0),size(n+1, 1) {
        iota(par.begin(), par.end(), 0);
    }

    T find(T x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(T x, T y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[x] = y;
            size[y] += size[x];
        }else{
            par[y] = x;
            size[x] += size[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(T x, T y){
        return find(x) == find(y);
    }

    T getsize(T x){
        return size[find(x)];
    }

    int rootCount(int n){
        int cnt = 0;
        reps(i, 0, n){
            if(i == par[i]) cnt++;
        }
        return cnt;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y, z;
    vector<pair<int, int>> xy;
    cin >> n >> m;
    rep(i, m){
        cin >> x >> y >> z;
        xy.push_back(make_pair(x, y));
    }

    UnionFind<int> uf(n);
    for(auto const& e : xy){
        uf.unite(e.first, e.second);
    }

    cout << uf.rootCount(n)-1 << endl;

    return 0;
}
