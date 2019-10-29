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
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "no" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "nO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


// dp[i][j] => i 番目までの品物の中から j を超えないように選んだ時の最大価値
ll n, W;
ll dp[110][100010];
ll w[110], v[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> W;
    rep(i, n){
        cin >> w[i] >> v[i];
    }

    // 初期化
    reps(j, 0, W){
        dp[0][j] = 0;
    }

    // 漸化式
    rep(i, n){
        reps(j, 0, W){
            if(j >= w[i]){
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}
