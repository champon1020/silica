// verify
// https://atcoder.jp/contests/abc034/tasks/abc034_c

#ifndef COMBINATION_TEST_HPP
#define COMBINATION_TEST_HPP

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../math/combination.hpp"
using comb::Comb;

void TestCombination(std::istream& in, std::ostream& out){
    int w, h;
    in >> w >> h;
    int n = max(w, h);
    int k = min(w, h);

    Comb c(n+k);

    out << c.res(n-1+k-1, k-1) << endl;
}

#endif //COMBINATION_TEST_HPP