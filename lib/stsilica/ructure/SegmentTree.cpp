#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


// from
class SegmentTree {
  public:
    ll n;
    vector<ll> dat;

    void init(ll nn){
        n = 1;
        while(n < nn) n*=2;
        dat.resize(2*n-1, inf);
    }

    void update(ll k, ll a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2 + 1], dat[k*2 + 2]);
        }
    }

    ll query(ll a, ll b, ll k, ll l, ll r){
        if(r <= a || b <= l) return inf;
        if(a <= l && r <= b) return dat[k];
        else{
            ll vl = query(a, b, k*2+1, l, (l+r)/2);
            ll vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }

    ll operator[](int i){
        return dat[i + n - 1];
    }
};
// to


int main() {
    
}
