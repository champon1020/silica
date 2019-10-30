#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from
class UnionFind{
  public:
    vector<ll> par;
    vector<ll> rank;
    vector<ll> size;
    UnionFind(ll n): par(n, 0),rank(n, 0),size(n, 1) { iota(par.begin(), par.end(), 0); }

    ll find(ll x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(ll x, ll y){
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

    bool same(ll x, ll y){
        return find(x) == find(y);
    }

    ll getsize(ll x){
        return size[find(x)];
    }
};
// to


// verify
// https://atc001.contest.atcoder.jp/tasks/unionfind_a
int main(){
    int n, q, p, a, b;
    cin >> n >> q;
    UnionFind tree(n);
    rep(i, q){
        cin >> p >> a >> b;
        if(p){
            ans(tree.same(a, b));
        }else{
            tree.unite(a, b);
        }
    }
    return 0;
}
