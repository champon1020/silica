#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
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


struct Pair {
    ll x, y, z;
    Pair(ll x, ll y, ll z):x(x),y(y),z(z){};
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    vector<Pair> xyz;
    ll x, y, z;
    cin >> n >> m;
    rep(i, n){
        cin >> x >> y >> z;
        xyz.push_back(Pair(x, y, z));
    }

    ll max = -inf;
    for(int bit=0; bit < (1<<3); bit++){
        vector<ll> sums;
        for(auto const& e : xyz){
            ll sum = 0;
            if(bit & (1<<0)) sum += -e.x;
            else sum += e.x;
            if(bit & (1<<1)) sum += -e.y;
            else sum += e.y;
            if(bit & (1<<2)) sum += -e.z;
            else sum += e.z;
            sums.push_back(sum);
        }

        //vdebug(sums);

        sort(all(sums), greater<ll>());

        ll sum = 0;
        rep(i, m){
            sum += sums[i];
        }
        chmax(max, sum);
    }

    cout << max << endl;

    return 0;
}
