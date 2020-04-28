#ifndef INCLUDE_LCA_HPP
#define INCLUDE_LCA_HPP

#include <vector>
using namespace std;

namespace lca_nsp {
	using ll = long long;
	ll inf = ll(1e18);

	class LCA {
	public:
		/** Sparse Table RMQ **/
		struct Cell {
			ll value; int idx;
			Cell(ll value, int idx):value(value),idx(idx){}
			bool operator<(Cell const& rhs) const {
				return value < rhs.value;
			}
		};
		vector<vector<Cell>> table;	// table[i][j]: i番目から2^j個見たときのRMQ
		template<typename T> void init_rmq(vector<T> &vec);
		int query(int l, int r);

		/** LCA **/
		int n;
		vector<vector<int>> g;
		// id: 各頂点のはじめに訪れたときのtrack
		// track: dfsの訪問順
		// depth: trackに対する深さ
		vector<ll> id, track, depth;
		LCA(int n):n(n){
			g = vector<vector<int>>(n);
		}
		void add(int from, int to);
		void build(int root);
		void dfs(int u, int par, int d, int &cnt);
		int res(int u, int v);
	};

	template<typename T>
	void LCA::init_rmq(vector<T> &vec) {
		int sz = vec.size();
		int logn = 31 - __builtin_clz(sz);	// sz <= 2^(logn) を満たす logn
		table = vector<vector<Cell>>(sz, vector<Cell>(logn+1, Cell(inf, -1)));

		for(int i=0; i<sz; i++) table[i][0] = Cell(vec[i], i);
		for(int j=0; j<logn; j++){
			for(int i=0; i<sz; i++){
				Cell buf = (i+(1<<j) < sz) ? table[i+(1<<j)][j] : Cell(inf, -1);
				table[i][j+1] = min(table[i][j], buf);
			}
		}
	}

	int LCA::query(int l, int r){
		int bit = 31 - __builtin_clz(r-l);
		return min(table[l][bit], table[r-(1<<bit)][bit]).idx;
	}

	void LCA::add(int from, int to) {
		g[from].push_back(to);
	}

	void LCA::build(int root) {
		id = vector<ll>(n);
		track = vector<ll>(2*n-1);
		depth = vector<ll>(2*n-1);
		int cnt = 0;
		dfs(root, -1, 0, cnt);
		init_rmq(depth);
	}

	void LCA::dfs(int u, int par, int d, int &cnt) {
		id[u] = cnt;
		track[cnt] = u;
		depth[cnt++] = d;
		for(auto& to : g[u]){
			if(to == par) continue;
			dfs(to, u, d+1, cnt);
			track[cnt] = u;
			depth[cnt++] = d;
		}
	}

	int LCA::res(int u, int v){
		if(id[u] > id[v]) swap(u, v);
		return track[query(id[u], id[v])];
	}
}

#endif //INCLUDE_LCA_HPP
