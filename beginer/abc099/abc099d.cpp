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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    int d[1010][1010];
    int g[3][40];
    rep(i, 3){
        Fill(g[i], 0);
    }

    cin >> n >> c;
    reps(i, 1, c){
        reps(j, 1, c){
            cin >> d[i][j];
        }
    }
    int cc;
    reps(i, 1, n){
        reps(j, 1, n){
            cin >> cc;
            g[(i+j)%3][cc]++;
        }
    }

    ll res = inf;
    reps(i, 1, c){
        reps(j, 1, c){
            if(i==j) continue;
            reps(k, 1, c){
                if(j==k || k==i) continue;
                ll sum = 0;
                reps(m, 1, c){
                    if(g[0][m] == 0) continue;
                    sum += d[m][i] * g[0][m];
                }
                reps(m, 1, c){
                    if(g[1][m] == 0) continue;
                    sum += d[m][j] * g[1][m];
                }
                reps(m, 1, c){
                    if(g[2][m] == 0) continue;
                    sum += d[m][k] * g[2][m];
                }
                //cout << sum << endl;
                res = min(res, sum);
            }
        }
    }

    cout << res << endl;

    // rep(i, 3){
    //     reps(j, 1, 30){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // reps(i, 1, 30){
    //     reps(j, 1, 30){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
