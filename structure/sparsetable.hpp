#ifndef INCLUDE_SPARSETABLE_HPP
#define INCLUDE_SPARSETABLE_HPP

#include <vector>
using namespace std;

namespace sparse {

using ll = long long;
ll inf = ll(1e18);

class SparseTable {
public:
  vector<vector<ll>> table;	// table[i][j]: i番目から2^j個見たときのRMQ

  template<typename T>
  explicit SparseTable(vector<T> vec) {
    int sz = vec.size();
    int logn = 31 - __builtin_clz(sz);	// sz <= 2^(logn) を満たす logn
    table = vector<vector<ll>>(sz, vector<ll>(logn+1, inf));

    for(int i=0; i<sz; i++) table[i][0] = vec[i];
    for(int j=0; j<logn; j++){
      for(int i=0; i<sz; i++){
        ll buf = (i+(1<<j) < sz) ? table[i+(1<<j)][j] : inf;
        table[i][j+1] = min(table[i][j], buf);
      }
    }
  }

  int query(int l, int r);
};

int SparseTable::query(int l, int r){
  int bit = 31 - __builtin_clz(r-l);
  return min(table[l][bit], table[r-(1<<bit)][bit]);
}

}

#endif //INCLUDE_SPARSETABLE_HPP
