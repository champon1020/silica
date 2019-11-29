#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define ll long long
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
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
ll keta(ll num){ ll k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, w, h;
    vector<pair<ll, ll>> wh;
    cin >> n;
    rep(i, n){
        cin >> w >> h;
        wh.push_back(make_pair(w, h));
    }

    sort(all(wh), comp);

    ll res = 1;
    pair<ll, ll> last = wh[0];
    reps(i, 1, n-1){
        if(wh[i].first == last.first) continue;
        if(wh[i].second < last.second){
            res++;
            last = wh[i];
        }
    }

    // cout << endl;
    // for(auto e : wh){
    //     cout << e.first sp e.second << endl;
    // }

    cout << res << endl;

    return 0;
}
