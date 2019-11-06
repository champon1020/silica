#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
using namespace std;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> T keta(T num){ T k=0; while(num>0){ num/=10; k++; } return k; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, k;
	ll ain;
	ll asum[1010];
	asum[0] = 0;
	cin >> n >> k;
	reps(i, 1, n){
		cin >> ain;
		asum[i] = asum[i-1] + ain;
	}
	
	vector<ll> bit[45];
	reps(l, 0, n){
		reps(r, l, n){
			ll num = asum[r]-asum[l];
			reps(i, 0, 40){
				if(num & 1LL<<i){
					bit[i].push_back(num);
				}
			}
		}
	}
	
	ll res = 0;
	vector<ll> dist;
	repr(i, 40, 0){
		if(bit[i].size() >= k){
			dist = bit[i];
			break;
		}
	}
	
	function<ll(vector<ll>) rec = [&](vector<ll> v) = {
		repr(i, 40, 0){
			for(auto const& vv : v){
				if(vv & (1LL<<i)){
					
				}
			}
		}
	};
	
	cout << res << endl;
	
	// debug
	/*
	reps(i, 0, 40){
		cout << bit[i].size() << endl;
	}
	adebug(asum, n);
	*/

    return 0;
}