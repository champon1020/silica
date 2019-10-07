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
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
    
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, d;
    cin >> n >> d;

    ll dp[101][7];
    rep(i, 7){
        dp[0][i] = d;
    }

    int cnt = 0;
    rep(i, n){
        reps(j, 1, 7){
            reps(k, 1, 7){
                dp[i+1][j] = dp[i][k] % j;
            }
        }
        reps(l, 1, 6){
            cout << dp[i+1][l] << " ";
        }
        cout << endl;
    }

    rep(i, n+1){
        reps(j, 1, 7){
            if(dp[i][j] == 0) cnt++;
        }
    }

    double res = cnt / pow(6, n);
    printf("%.10lf", res);
    return 0;
}