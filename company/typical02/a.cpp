#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e10
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<lli>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
using namespace std;
using ll = long long;
template<typename T> bool chmax(T &a, T &b){ if(a<b) { a=b; return 1; }}
template<typename T> bool chmin(T &a, T &b){ if(b<a) { a=b; return 1; }}
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*b/gcd(a, b); }
template<typename T> T vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> T adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
 
 
int r, c;
int sx, sy, gy, gx;
int g[100][100];
queue<pair<int, int>> q;
int visit[100][100];
 
void bfs(){
    int cnt=0;
    q.push(make_pair(sx-1, sy-1));
    visit[sx-1][sy-1] = 0;
    while(!q.empty()){
        pair<int, int> buf = q.front();
        q.pop();
        //visit[buf.first][buf.second] += 1;
 
        rep(i, 4){
            int deltax = buf.first+dx[i];
            int deltay = buf.second+dy[i];
            if(deltax < 0 || deltax >= c || deltay < 0 || deltay >= r) continue;
            if(visit[deltax][deltay] != 0) continue;
            if(g[deltax][deltay] == 0) continue;
 
            q.push(make_pair(deltax, deltay));
            visit[deltax][deltay] = visit[buf.first][buf.second] + 1;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    char tmp;
    cin >> r >> c;
    cin >> sy >> sx >> gy >> gx;
 
    rep(i, r){
        rep(j, c){
            cin >> tmp;
            g[j][i] = (tmp == '.');
        }
    }
 
    rep(i, r){
        rep(j, c){
            visit[j][i] = 0;
        }
    }
 
    bfs();
 
    cout << visit[gx-1][gy-1] << endl;
 
    return 0;
}