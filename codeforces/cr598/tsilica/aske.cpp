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

    sort(all(a), greater<pair<ll, int>>());
    for(auto const& e : a){
        cout << e.second << " ";
    }for(auto const& e : a){
        cout << e.first << " ";
    }
    cout << endl;

    ll dp[200010];
    int res[200010];
    dp[3] = a[0].first - a[2].first;
    res[a[0].second] = res[a[1].second] = res[a[2].second] = 1;
    int team_num = 1;
    reps(i, 3, n-1){
        //cout << i << endl;
        if(i+2 <= n-1){
            // add to team
            if(dp[i] + a[i-1].first - a[i].first <= dp[i] + a[i].first - a[i+2].first){
                cout << i << endl;
                dp[i+1] = dp[i] + a[i-1].first - a[i].first;
                res[a[i].second] = team_num;
            // devide team
            }else{
                //cout << i << endl;
                dp[i+1] = dp[i+2] = dp[i+3] = dp[i] + a[i].first - a[i+2].first;
                res[a[i].second] = res[a[i+1].second] = res[a[i+2].second] = ++team_num;
                i += 2;
            }
        }else{
            //cout << i sp i+1 << endl;
            //cout << a[i].second sp a[i+1].second << endl;
            res[a[i].second] = res[a[i+1].second] = team_num;
            break;
        }
    }

    cout << team_num << endl;
    rep(i, n){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
