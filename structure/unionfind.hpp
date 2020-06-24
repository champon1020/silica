#ifndef DEFINE_UNIONFIND_HPP
#define DEFINE_UNIONFIND_HPP

#include <vector>
#include <numeric>

using namespace std;

namespace unionfind {

using ll = long long;

class UnionFind {
public:
  ll n;
  vector<ll> par;
  vector<ll> rank;
  vector<ll> size;

  UnionFind(int n);
  ll find(ll x);
  void unite(ll x, ll y);
  bool same(ll x, ll y);
  ll getsize(ll x);
  int rootCount();
};

UnionFind::UnionFind(int n):n(n), par(n, 0), rank(n, 0), size(n, 1) {
  iota(par.begin(), par.end(), 0);
}

ll UnionFind::find(ll x) {
  if (par[x] == x) return x;
  else return par[x] = find(par[x]);
}

void UnionFind::unite(ll x, ll y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rank[x] < rank[y]) {
    par[x] = y;
    size[y] += size[x];
  } else {
    par[y] = x;
    size[x] += size[y];
    if (rank[x] == rank[y]) rank[x]++;
  }
}

bool UnionFind::same(ll x, ll y) {
  return find(x) == find(y);
}

// get size of tree
ll UnionFind::getsize(ll x) {
  return size[find(x)];
}

// get the number of roots
int UnionFind::rootCount() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == par[i]) cnt++;
  }
  return cnt;
}


// verify
// https://atc001.contest.atcoder.jp/tasks/unionfind_a

}

#endif //DEFINE_UNIONFIND_HPP