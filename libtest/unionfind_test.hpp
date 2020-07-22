// verify
// https://atc001.contest.atcoder.jp/tasks/unionfind_a

#include <bits/stdc++.h>
using namespace std;
usind ll = long long;
ll inf = 1e18;
#include "../graph/dijkstra.hpp"

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

