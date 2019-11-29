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
    

ll dp[101][5][5][5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    dp[0][0][0][0] = 1;

    rep(i, n){
        rep(j, 5){
            rep(k, 5){
                rep(l, 5){
                    reps(m, 1, 5){
                        if(k == 1 && l == 3 && m == 2) continue;
                        if(k == 3 && l == 1 && m == 2) continue;
                        if(k == 1 && l == 2 && m == 3) continue;
                        if(j == 1 && k == 3 && m == 2) continue;
                        if(j == 1 && l == 3 && m == 2) continue;
                        dp[i+1][k][l][m] += dp[i][j][k][l];
                        dp[i+1][k][l][m] %= ll(1e9+7);
                    }
                }
            }
        }
    }

    ll res = 0;
    reps(i, 1, 5){
        reps(j, 1, 5){
            reps(k, 1, 5){
                res += dp[n][i][j][k];
                res %= ll(1e9+7);
            }
        }
    }

    cout << res << endl;
    
    return 0;
}