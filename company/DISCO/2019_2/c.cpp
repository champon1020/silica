#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename T> inline bool chmax(T &a, T b){ if(a<b) a=b; return a<b; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a) a=b; return b<a; }
template<typename T> void vdeb(T v){
    cout << "#vector set debug" << endl;
    for(auto vv : v) cout << vv << " ";
    cout << endl;
}
template<typename T1, typename T2> void adeb(T1 arr[], T2 n){
    cout << "#adebug" << endl;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
template<typename T1> void mdeb(T1 mp){
    cout << "#map pair debug" << endl;
    for(auto const& m : mp) cout << m.first sp m.second << endl;
}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){ fill((T*)array, (T*)(array+N), val); }
void ans(bool b){ cout << (b ? "Yes" : "No") << endl; }
void ans2(bool b){ cout << (b ? "YES" : "NO") << endl; }
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, k;
    cin >> h >> w >> k;
    char in;
    int g[333][333];
    rep(i, h){
        rep(j, w){
            cin >> in;
            if(in == '.') g[i][j] = 0;
            if(in == '#') g[i][j] = 1;
        }
    }

    set<int> aftercare;
    int res[333][333];
    int cnt = 1;
    int now = 0;
    rep(i, h){
        rep(j, w){
            if(!g[i][j]){
                res[i][j] = cnt;
                continue;
            }
            if(now == 0 && g[i][j]){
                now++;
                res[i][j] = cnt;
                continue;
            }
            if(now >= 1 && g[i][j]){
                now++;
                res[i][j] = ++cnt;
                continue;
            }
        }
        if(now == 0){
            rep(j, w){
                res[i][j] = 0;
            }
        }else{
            cnt++;
        }
        now = 0;
    }

    reps(i, 1, h-1){
        rep(j, w){
            if(res[i][j] == 0){
                res[i][j] = res[i-1][j];
            }
        }
    }
    repr(i, h-2, 0){
        rep(j, w){
            if(res[i][j] == 0){
                res[i][j] = res[i+1][j]; 
            }
        }
    }

    rep(i, h){
        rep(j, w){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
