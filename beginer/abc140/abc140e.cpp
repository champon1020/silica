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


class SegmentTree {
  public:
    ll n;
    vector<pair<ll, ll>> dat;

    void init(ll nn){
        n = 1;
        while(n < nn) n*=2;
        dat.assign(2*n-1, make_pair(0, 0));
    }

    void update(ll k, ll a){
        k += n-1;
        if(a > dat[k].first){
            dat[k].second = dat[k].first;
            dat[k].first = a;
        }else if(dat[k].first >= a && a >= dat[k].second){
            dat[k].second = a;
        }else return;

        while(k > 0){
            k = (k-1)/2;
            dat[k].first = max(dat[k*2 + 1].first, dat[k*2 + 2].first);
            dat[k].second = min(dat[k*2 + 1].first, dat[k*2 + 2].second);
        }
    }

    ll query(ll a, ll b, ll k, ll l, ll r){
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return dat[k].second;
        else{
            ll vl = query(a, b, k*2+1, l, (l+r)/2);
            ll vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }

    ll getquery(ll a, ll b){
        return query(a, b, 0, 0, n-1);
    }

    ll operator[](int i){
        return dat[i + n - 1].second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll p;
    cin >> n;
    SegmentTree t(n);
    rep(i, n){
        cin >> p;
        t.update(i, p);
    }

    ll res = 0;
    

    return 0;
}
