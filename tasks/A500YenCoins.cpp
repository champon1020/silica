#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ceill(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
void ans(bool b){ cout << (b ? "Yes" : "No") << endl; }
void ans2(bool b){ cout << (b ? "YES" : "NO") << endl; }
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill((T*)array, (T*)(array+N), val);
}
template<typename T> void vdeb(T v){
    cout << "#vector set debug" << endl;
    for(auto vv : v) cout << vv << " ";
    cout << endl;
}
template<typename T1, typename T2> void adeb(T1 arr[], T2 n){
    cout << "#adebug" << endl;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
template<typename T1> void mdeb(T1 mp){
    cout << "#map pair debug" << endl;
    for(auto const& m : mp) cout << m.first sp m.second << endl;
}
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


class A500YenCoins {
public:
	void solve(std::istream& in, std::ostream& out) {
        int k, x;
        in >> k >> x;
        if(500*k >= x) out << "Yes" << endl;
        else out << "No" << endl;
	}
};
