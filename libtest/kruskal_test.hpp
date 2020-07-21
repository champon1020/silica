// verify
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

#ifndef KRUSKAL_TEST_HPP
#define KRUSKAL_TEST_HPP

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../graph/kruskal.hpp"
using kruskal::Kruskal;

void TestKruskal(std::istream& in, std::ostream& out) {
    int v, e;
    in >> v >> e;
    Kruskal kr(v, e);
    ll s, t, w;
    for(int i=0; i<e; i++){
        in >> s >> t >> w;
        kr.add(s, t, w);
    }

    out << kr.compute() << endl;
}

#endif //KRUSKAL_TEST_HPP
