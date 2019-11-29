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


int dp[51][10001][51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, n, k, aa, bb;
    vector<int> a, b;
    cin >> w >> n >> k;
    rep(i, n){
        cin >> aa >> bb;
        a.push_back(aa);
        b.push_back(bb);
    }

    dp[0][0][0] = 0;

    //dp[i][j][kk] i番目まででkk個選んだときの幅合計jでの最大価値
    int res = 0;
    rep(i, n){
        rep(kk, k+1){
            rep(j, w+1){
                // ab[i]を選ぶとき
                if(j+a[i] <= w){
                    dp[i+1][j+a[i]][kk+1] = max(dp[i][j][kk]+b[i], dp[i][j+a[i]][kk]);
                }
                // ab[i]を選ばないとき
                dp[i+1][j][kk] = max(dp[i+1][j][kk], dp[i][j][kk]);
            }
        }
    }

    cout << dp[n][w][k] << endl;

    return 0;
}