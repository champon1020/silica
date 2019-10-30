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


vector<vector<ll>> dp(1010, vector<ll>(1010, -1));
ll a[1010][1010];
ll mod = 1e9+7;
int h, w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    

    function<ll(int, int)>dfs = [&](int x, int y) -> ll{
        if(dp[y][x] >= 0) return dp[y][x];
        ll res = 0;
        rep(i, 4){
            int dlx = x + dx[i];
            int dly = y + dy[i];
            if(dlx < 0 || w <= dlx || dly < 0 || h <= dly) continue;
            if(a[dly][dlx] > a[y][x]) res += dfs(dlx, dly) + 1;
            res %= mod;
        }
        dp[y][x] = res;
        return res;
    };

    ll res = h*w;
    rep(y, h){
        rep(x, w){
            res += dfs(x, y);
            res %= mod;
        }
    }

    cout << res << endl;

    return 0;
}
