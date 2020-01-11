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


template<typename T>
class Perm {
public:
    ll n;
    vector<T> p;
    vector<vector<T>> p_v;
    Perm(ll n):n(n){}

    void build() {
        vector<T> v(n);
        iota(v.begin(), v.end(), 1);
        do {
            ll num = 0;
            for(ll i=0; i<v.size(); i++) num += pow(10, v.size()-(i+1)) * v[i];
            p.push_back(num);
        }while(next_permutation(v.begin(), v.end()));
    }

    void build_v(){
        ll size = 1;
        for(ll i=0; i<=n; i++) size *= i;
        p_v.assign(size);
        vector<T> v(n);
        iota(v.begin(), v.end(), 1);
        ll ind = 0;
        do {
            for(auto const e : v) p_v[ind].push_back(e);
            ind++;
        }while(next_permutation(v.begin(), v.end()));
    }
};

class CCountOrder {
public:
	void solve(std::istream& in, std::ostream& out) {
        int n;
        int p[10], q[10];
        ll p_num = 0, q_num = 0;
        in >> n;
        rep(i, n){
            in >> p[i];
            p_num += pow(10, n-(i+1)) * p[i];
        }
        rep(i, n){
            in >> q[i];
            q_num += pow(10, n-(i+1)) * q[i];
        }

        Perm<int> perm(n);
        perm.build();

        int a = distance(perm.p.begin(), upper_bound(all(perm.p), p_num));
        int b = distance(perm.p.begin(), upper_bound(all(perm.p), q_num));

        out << abs(a - b) << endl;
	}
};
