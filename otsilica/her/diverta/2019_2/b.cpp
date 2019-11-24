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
    ll x, y;
    vector<pair<ll, ll>> xy;
    cin >> n;
    rep(i, n){
        cin >> x >> y;
        xy.push_back(make_pair(x, y));
    }

    vector<pair<ll, ll>> diffs;
    rep(i, xy.size()){
        rep(j, xy.size()){
            if(i==j) continue;
            diffs.push_back(make_pair(xy[i].first-xy[j].first, xy[i].second-xy[j].second));
        }
    }

    sort(all(diffs));

    ll maxcnt = 0;
    ll cnt = 0;
    ll nowx=inf, nowy=inf;
    for(auto const& e : diffs){
        if(e.first == 0 && e.second == 0){
            continue;
        }
        if(nowx==inf && nowy==inf){
            nowx = e.first;
            nowy = e.second;
            continue;
        }
        if(nowx == e.first && nowy == e.second){
            cnt++;
        }else{
            if(cnt != 0) chmax(maxcnt, cnt);
            cnt = 0;
        }
        nowx = e.first;
        nowy = e.second;
    }


    ll res;
    res = n!=1 ? (n-1)-maxcnt : 1;

    cout << res << endl;

    // for(auto const& e : diffs){
    //     cout << e.first sp e.second << endl;
    // }

    return 0;
}
