// verify
// https://atcoder.jp/contests/abc070/tasks/abc070_d

#include <bits/stdc++.h>
using namespace std;
usind ll = long long;
ll inf = 1e18;
#include "../graph/dijkstra.hpp"

int main(){
    int n, a, b;
    ll c;
    in >> n;
    Dijkstra<ll> dk(n);
    for(int i=0; i<n-1; i++){
        in >> a >> b >> c;
        a--; b--;
        dk.add(a, b, c);
        dk.add(b, a, c);
    }
    int q, k, x, y;
    in >> q >> k;
    dk.build(--k);
    for(int i=0; i<q; i++){
        in >> x >> y;
        out << dk.result(--x) + dk.result(--y) << endl;
    }
}