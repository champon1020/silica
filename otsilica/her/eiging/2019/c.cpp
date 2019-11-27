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

    int h, w;
    int g[500][500];
    vector<pair<int, int>> black_xy;
    char tmp;
    cin >> h >> w;
    rep(i, h){
        rep(j, w){
            cin >> tmp;
            if(tmp == '#'){
                g[j][i] = 1;
                black_xy.push_back(make_pair(j, i));
            }else g[j][i] = 0;
        }
    }

    int visit[500][500];
    int black_visit[500][500];
    Fill(visit, 0);
    Fill(black_visit, 0);
    ll cntbuf, black_cnt;
    function<void(int, int)> dfs = [&](int x, int y){
        visit[x][y] = 1;
        if(g[x][y]){
            black_visit[x][y] = 1;
            black_cnt++;
        }else cntbuf++;

        rep(i, 4){
            int dlx = x + dx[i];
            int dly = y + dy[i];
            if(dlx < 0 || dlx >= w || dly < 0 || dly >= h) continue;
            if(visit[dlx][dly]) continue;
            if(g[x][y] && !g[dlx][dly]){
                dfs(dlx, dly);
            }else if(!g[x][y] && g[dlx][dly]){
                dfs(dlx, dly);
            }
        }
    };

    ll res = 0;
    for(auto const& e : black_xy){
        int x = e.first;
        int y = e.second;
        if(black_visit[x][y]) continue;
        cntbuf = 0;
        black_cnt = 0;
        dfs(x, y);
        res += cntbuf*black_cnt;
    }

    cout << res << endl;

    return 0;
}
