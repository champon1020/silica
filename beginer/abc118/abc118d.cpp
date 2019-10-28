#include <bits/stdc++.h>
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
using ll = long long;
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

ll dp[10010];
ll dp2[10010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, tmp;
    ll b[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<ll> a;

    cin >> n >> m;
    rep(i, m){
        cin >> tmp;
        a.push_back(tmp);
    }

    vsortr(a);

    dp[0] = 0;
    reps(i, 1, n){
        dp[i] = -inf;
        rep(j, a.size()){
            int num = b[a[j]];
            if(i >= num) dp[i] = max(dp[i], dp[i-num]+1);
        }
        //cout << dp[i] << " ";
    }

    string res = "";
    while(n > 0){
        for(auto aa : a){
            int num = b[aa];
            if(dp[n]-1 == dp[n-num] && n >= num){
                //cout << dp[n-num] sp n sp num << endl;
                res += to_string(aa);
                n -= num;
                break;
            }
        }
        //cout << n << endl;
    }

    cout << res << endl;

    return 0;
}
