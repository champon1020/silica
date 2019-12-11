#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define ll long long
using namespace std;


// from
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
