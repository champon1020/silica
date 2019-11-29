#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


ll h, w, k;
ll dp[110][10];
ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> k;

    Fill(dp, 0);
    reps(i, 0, w){
        dp[0][i] = i==1 ? 1 : 0;
    }

    if(w == 1){
        cout << 1 << endl;
        return 0;
    }

    reps(i, 0, h){
        reps(j, 1, w){
            for(ll e=0; e < (1<<(w-1)); e++){
                bool flg = true;
                for(int l=0; l<w-2; l++){
                    if((e & 1<<l) && (e & 1<<(l+1))) flg = false;
                }
                if(!flg) continue;

                // h+1, x-1
                if((1<<(j-2) & e) && j-1 >= 0){
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= mod;
                }
                // h+1, x+1
                else if((1<<(j-1) & e) && j+1 <= w){
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= mod;
                }
                else{
                    // h+1, x
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= mod;
                }
            }
        }
    }

    cout << dp[h][k] << endl;

    // reps(i, 0, h){
    //     reps(j, 1, w){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
