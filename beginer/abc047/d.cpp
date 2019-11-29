#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
#define enl << endl
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


const int MAXN = 100010;

class SegmentTree {
public:
    vector<ll> dat;
    ll n;

    SegmentTree(ll nn){
        n = 1;
        while(n < nn) n*=2;
        dat.resize(2*n-1, 0);
    }

    void update(ll k, ll x){
        k += n-1;
        dat[k] = x;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = max(dat[2*k+1], dat[2*k+2]);
        }
    }

    ll getmax(ll a, ll b, ll k, ll l, ll r){
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return dat[k];
        else{
            ll v1 = getmax(a, b, 2*k+1, l, (l+r)/2);
            ll v2 = getmax(a, b, 2*k+2, (l+r)/2, r);
            return max(v1, v2);
        }
    }

    ll get(ll a, ll b){
        //cout << n << endl;
        return getmax(a, b, 0, 0, n);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, t, tmpa;
    vector<ll> a;

    cin >> n >> t;
    rep(i, n){
        cin >> tmpa;
        a.push_back(tmpa);
    }

    SegmentTree tree(n);

    rep(i, n){
        tree.update(i, a[i]);
    }

    ll res[100010];
    reps(i, 0, n-2){
        res[i] = tree.get(i+1, n) - a[i];
    }
    res[n-1] = -a[n-1];

    //adebug(res, n);

    ll maxres = 0;
    ll maxcnt = 0;
    rep(i, n){
        if(res[i] > maxres){
            maxres = res[i];
            maxcnt = 1;
        }else if(res[i] == maxres){
            maxcnt++;
        }
    }

    //cout << maxres << endl;
    cout << maxcnt << endl;

    return 0;
}
