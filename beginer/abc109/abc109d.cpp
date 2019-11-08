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


int h, w, tmpa;
int a[510][510];
int done[510][510];
vector<pair<ll, ll>> from;
vector<pair<ll, ll>> to;

void dfs(int x, int y){
    rep(i, 4){
        int dlx = x + dx[i];
        int dly = y + dy[i];
        if(dlx < 0 || dlx >= w || dly < 0 || dly >= h) continue;
        if(done[dlx][dly]) continue;
        if(a[x][y]%2 == 0){
            done[x][y] = 1;
            dfs(dlx, dly);
            break;
        }
        if(!done[x][y]){
            a[dlx][dly] += 1;
            a[x][y] -= 1;
            done[x][y] = 1;
            from.push_back(make_pair(y+1, x+1));
            to.push_back(make_pair(dly+1, dlx+1));
        }
        dfs(dlx, dly);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    rep(y, h){
        rep(x, w){
            cin >> a[x][y];
        }
    }

    Fill(done, 0);

    dfs(0, 0);

    cout << from.size() << endl;
    rep(i, from.size()){
        cout << from[i].first sp from[i].second sp to[i].first sp to[i].second << endl;
    }

    // cout << endl;
    // rep(y, h){
    //     rep(x, w){
    //         cout << a[x][y] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
