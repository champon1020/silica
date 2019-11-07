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

    ll n, tmpa;
    vector<pair<ll, ll>> a;
    vector<pair<ll, ll>> group[200010];
    cin >> n;
    rep(i, n){
        cin >> tmpa;
        a.push_back(make_pair(tmpa, i));
    }
    vsort(a);

    // for(auto const& e : a){
    //     cout << e.first sp e.second << endl;
    // }

    ll g_ind = 0;
    ll res = 0;
    group[g_ind].push_back(a[0]);
    reps(i, 1, n-2){
        if(a[i+1].first - a[i].first > a[i].first - a[i-1].first
            || a[i].first -a[i-1].first == 0
            || group[g_ind].size() < 3
            || n-i < 3){
            //cout << a[i+1].first - a[i].first sp a[i].first - a[i-1].first sp a[i].first << endl;
            group[g_ind].push_back(a[i]);
        }else{
            group[++g_ind].push_back(a[i]);
        }
    }
    group[g_ind].push_back(a[n-1]);

    ll resarr[200010];
    reps(i, 0, g_ind){
        if(group[i].size() <= 0) continue;
        for(auto const& g : group[i]){
            resarr[g.second] = i+1;
            //cout << g << endl;
        }
        res += group[i][group[i].size()-1].first - group[i][0].first;
    }

    cout << res sp g_ind+1 << endl;
    rep(i, n){
        cout << resarr[i] << " ";
    }
    cout << endl;

    return 0;
}
