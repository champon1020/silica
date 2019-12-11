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

    int n;
    ll tmpa;
    vector<pair<ll, int>> a;
    cin >> n;
    rep(i, n){
        cin >> tmpa;
        a.push_back(make_pair(tmpa, i));
    }

    vsort(a);
    ll team_num = 1;
    ll dp[200010];
    ll res[200010];
    Fill(dp, inf);
    dp[0] = 0;
    res[a[0].second] = res[a[1].second] = res[a[2].second] = 1;
    reps(i, 0, n-5){
        if(dp[i+3] > dp[i] + a[i+2].first - a[i].first){
            dp[i+3] = dp[i] + a[i+2].first - a[i].first;
            res[a[i+2].second] = res[a[i+1].second];
        }else res[a[i+2].second] = res[a[i].second]+1;

        if(dp[i+4] > dp[i] + a[i+3].first - a[i].first){
            dp[i+4] = dp[i] + a[i+3].first - a[i].first;
            res[a[i+3].second] = res[a[i+2].second];
        }else res[a[i+3].second] = res[a[i].second]+1;

        if(dp[i+5] > dp[i] + a[i+4].first - a[i].first){
            dp[i+5] = dp[i] + a[i+4].first - a[i].first;
            res[a[i+4].second] = res[a[i+3].second];
        }else res[a[i+4].second] = res[a[i].second]+1;
    }

    cout << dp[n] sp res[a[n-1].second] << endl;
    rep(i, n){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
