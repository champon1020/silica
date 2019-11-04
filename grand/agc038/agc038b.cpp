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
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


class SegmentTree {
  public:
    ll n;
    vector<ll> dat;

    void init(ll nn){
        n = 1;
        while(n < nn) n*=2;
        dat.resize(2*n-1, -1);
    }

    void update(ll k, ll a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = max(dat[k*2 + 1], dat[k*2 + 2]);
        }
    }

    ll query(ll a, ll b, ll k, ll l, ll r){
        if(r <= a || b <= l) return -1;
        if(a <= l && r <= b) return dat[k];
        else{
            ll vl = query(a, b, k*2+1, l, (l+r)/2);
            ll vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }

    ll getmax(ll a, ll b){
        return query(a, b, 0, 0, n-1);
    }

    ll operator[](int i){
        return dat[i + n - 1];
    }
};


class SegmentTree2 {
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

    ll getquery(ll a, ll b){
        return query(a, b, 0, 0, n-1);
    }

    ll operator[](int i){
        return dat[i + n - 1];
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    ll p[200010];
    SegmentTree tree;
    SegmentTree2 tree2;
    cin >> n >> k;
    tree.init(n);
    tree2.init(n);

    rep(i, n){
        cin >> p[i];
        tree.update(i, p[i]);
        tree2.update(i, p[i]);
    }

    bool flg = false;
    ll cnt = 1;
    ll l=0, r=k-1;
    while(r <= n-1){
        if(l > 0){
            if(p[r] != tree.getmax(l, r) || p[l-1] != tree2.getquery(l-1, r-1)){
                cnt++;
            }
        }
        l++; r++;
    }

    int seqcnt = 0;
    int th = 0;
    reps(i, 1, n-1){
        if(p[i] > p[i-1]){
            th++;
        }else{
            th = 0;
            continue;
        }
        if(th >= k-1){
            seqcnt++;
        }
    }

    if(seqcnt > 0){
        cnt -= seqcnt-1;
    }

    cout << cnt << endl;

    return 0;
}
