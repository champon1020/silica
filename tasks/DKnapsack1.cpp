#include <bits/stdc++.h>
#define ok cout << "ok" << endl;
#define sp << " " <<
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll inf = ll(5e18);
template<typename T1, typename T2> ll ceill(T1 a, T2 b){ return (a+b-1)/b; }
void ans(bool b, ostream& out=cout){ out << (b ? "Yes" : "No") << endl; }
void ans2(bool b, ostream& out=cout){ out << (b ? "YES" : "NO") << endl; }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){a=b; return true;} return false; }
template<typename T> inline bool chmin(T &a, T b){ if(a>b){a=b; return true;} return false; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

#include "../debug/debug.hpp"
debug debug;

class DKnapsack1 {
public:
	void solve(std::istream& in, std::ostream& out)
	{
	    int n, W;
	    in >> n;
	    vector<int> w(n), v(n);
	    for(int i=0; i<n; i++){
	        in >> w[i] >> v[i];
	    }

	    ll dp[110][100010];
	    Fill(dp, 0LL);
	}
};
