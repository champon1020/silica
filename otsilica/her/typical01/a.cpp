#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int h, w;
char g[501][501];
pair<int, int> start, goal;
int visit[501][501];
bool flg = false;

bool dfs(int x, int y){
    visit[x][y] = 1;
    if(x == goal.first && y == goal.second) return true;
    //cout << x << " " << y << endl;
    rep(i, 4){
        int deltax = x + dx[i];
        int deltay = y + dy[i];
        if(deltax < 0 || w <= deltax || deltay < 0 || h <= deltay) continue;
        if(visit[deltax][deltay]) continue;
        if(g[deltax][deltay] == '#') continue;
        if(dfs(deltax, deltay)) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string bufs;
    cin >> h >> w;
    rep(i, h){
        cin >> bufs;
        rep(j, w){
            if(bufs[j] == '#') g[j][i] = '#';
            else g[j][i] = '.';
            if(bufs[j] == 's') start = make_pair(j, i);
            if(bufs[j] == 'g') goal = make_pair(j, i);
        }
    }

    ans(dfs(start.first, start.second));

    return 0;
}