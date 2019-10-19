#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


/* dp[i][j] は i,j 間の最短距離 */
ll dp[310][310];
/* gas[i][j] は i,j 間の最小必要燃料 */
ll gas[310][310];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    /**
     * inf で初期化．
     * i = jのときは往復なので0．
     */
    rep(i, 310){
        rep(j, 310){
            dp[i][j] = inf;
            gas[i][j] = inf;
        }
        dp[i][i] = 0;
        gas[i][i] = 0;
    }

    /* 入力 */
    int n, m, a, b, c;
    ll l;
    cin >> n >> m >> l;
    rep(i, m){
        cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }

    /* dpについてワーシャルフロイド法 */
    rep(k, n+1){
        rep(i, n+1){
            rep(j, n+1){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    /* dp <= lのときのi,jを重み1とした無向グラフgas[i][j] */
    rep(i, n+1){
        rep(j, n+1){
            if(dp[i][j] <= l) gas[i][j] = min(gas[i][j], 1LL);
        }
    }

    /* gasについてワーシャルフロイド法 */
    rep(k, n+1){
        rep(i, n+1){
            rep(j, n+1){
                gas[i][j] = min(gas[i][j], gas[i][k] + gas[k][j]);
            }
        }
    }

    /* 出力 */
    int q, s, t;
    cin >> q;
    rep(i, q){
        cin >> s >> t;
        if(gas[s][t] >= 1e9){
            cout << -1 << endl;
        }else{
            cout << gas[s][t]-1 << endl;
        }
    }

    return 0;
}
