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


int sum = 0;
int g[10][10];
int visit[10][10];
bool flg = false;

void init(){
    rep(i, 10){
        rep(j, 10){
            visit[i][j] = 0;
        }
    }
}

void dfs(int x, int y){
    visit[x][y] = 1;
    sum++;

    rep(i, 4){
        int deltax = x+dx[i];
        int deltay = y+dy[i];
        if(deltax < 0 || deltax >= 10 || deltay < 0 || deltay >= 10) continue;
        if(visit[deltax][deltay] == 1) continue;
        if(g[deltax][deltay] == 0) continue;
        dfs(deltax, deltay);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char tmp;
    int cnt=1;
    rep(i, 10){
        rep(j, 10){
            cin >> tmp;
            if(tmp == 'x'){
                g[i][j] = 0;
            }else{
                g[i][j] = 1;
                cnt++;
            }
        }
    }

    init();

    rep(i, 10){
        rep(j, 10){
            if(g[i][j] == 0){
                g[i][j] = 1;
                flg = true;
            }
            
            dfs(i, j);
            if(sum == cnt){
                ans2(true);
                return 0;
            }

            if(flg){
                g[i][j] = 0;
                flg = false;
            }
            sum = 0;
            init();
        }
    }

    ans2(false);

    return 0;
}