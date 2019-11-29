#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
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
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    int n;
    ll a[10010];
    cin >> h >> w >> n;
    rep(i, n){
        cin >> a[i];
    }

    int g[110][110];
    rep(i, h){
        rep(j, w){
            g[i][j] = 0;
        }
    }

    int hh=0, ww=0;
    int dire = 1;
    rep(i, n){
        int cnt=0;
        while(cnt < a[i]){
            g[hh][ww] = i+1;
            if((ww == 0 && g[hh][ww+1] != 0) || (ww == w-1 && g[hh][ww-1] != 0) || (w == 1)){
                hh++;
                dire = (ww == 0) ? 1 : -1;
            }else{
                ww += dire;
            }
            cnt++;
        }
    }

    rep(i, h){
        rep(j, w){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
