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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    ll k;
    cin >> s >> k;

    ll cnt = 1;
    vector<ll> v;
    int slen = s.length();
    reps(i, 1, slen-1){
        if(s[i] == s[i-1])cnt++;
        else{
            if(cnt > 1){
                v.push_back(cnt);
                cnt = 1;
            }
        }
    }
    if(cnt > 1) v.push_back(cnt);

    ll res = 0;
    if(cnt == slen) res = slen*k/2;
    else{
        for(auto const& vv : v) res += vv/2;
        res *= k;
        if(s[0] == s[slen-1]){
            res -= (v[0]/2 + v[sz(v)-1]/2 - (v[0] + v[sz(v)-1])/2) * (k-1);
        }
    }

    cout << res << endl;

    return 0;
}
