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


int h, w;
int g[100][100];
queue<pair<int, int>> q;
int visit[100][100];

int bfs(){
    q.push(make_pair(0, 0));
    int res = 0;
    bool flg = false;

    while(!q.empty()){
        pair<int, int> e = q.front();
        q.pop();
        //visit[e.first][e.second] = 1;

        int x = e.first;
        int y = e.second;

        if(x == w-1 && y == h-1){
            res = visit[x][y] + 1;
            flg = true;
            break;
        }

        rep(i, 4){
            int deltax = x + dx[i];
            int deltay = y + dy[i];
            if(deltax < 0 || deltax >= w || deltay < 0 || deltay >= h) continue;
            if(visit[deltax][deltay] > 0) continue;
            if(g[deltax][deltay] == 0) continue;

            q.push(make_pair(deltax, deltay));
            visit[deltax][deltay] = visit[x][y] + 1;
        }
    }

    if(!flg){
        return -1;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char tmp;
    int cnt = 0;
    cin >> h >> w;
    rep(i, h){
        rep(j, w){
            cin >> tmp;
            g[j][i] = (tmp=='.');
            if(tmp=='#') cnt++;
        }
    }

    int res = bfs();

    if(res == -1){
        cout << -1 << endl;
        return 0;
    }

    cout << (h*w)-res-cnt << endl;

    return 0;
}