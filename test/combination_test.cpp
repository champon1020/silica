// verify
// https://atcoder.jp/contests/abc034/tasks/abc034_c

#include <bits/stdc++.h>
using namespace std;
usind ll = long long;
ll inf = 1e18;
#include "../math/combination.hpp"

int main(){
    int w, h;
    in >> w >> h;
    int n = max(w, h);
    int k = min(w, h);

    Comb<ll> c;
    c.build(n+k);

    out << c.result(n-1+k-1, k-1) << endl;
}