// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4

#include <bits/stdc++.h>
using namespace std;
usind ll = long long;
ll inf = 1e18;
#include "../graph/warshallfloyd.hpp"

int main(){
    int n, m;
    int a, b, t;
    in >> n >> m;
    WarshallFloyd<ll> wf(n, inf);
    for(int i=0; i<m; i++){
        in >> a >> b >> t;
        a--; b--;
        wf.add(a, b, t);
        wf.add(b, a, t);
    }

    wf.build();

    ll res = inf;
    for(int i=0; i<n; i++){
        ll mx = 0;
        for(int j=0; j<n; j++){
            mx = max(mx, wf.result(i, j));
        }
        res = min(res, mx);
    }

    out << res << endl;
}
