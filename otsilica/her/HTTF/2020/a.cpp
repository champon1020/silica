#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define sz(x) x.size()
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
using namespace std;
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> T gcd(T a, T b){ if(b==0) return a; return gcd(b, a%b); }
template<typename T> T lcm(T a, T b){ return a*(b/gcd(a, b)); }
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
ll keta(ll num){ ll k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


struct Bot {
    int rx, ry, c;
    Bot(int rx_, int ry_, int c_) : rx(rx_),ry(ry_),c(c_){}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, B, gx, gy;
    int tmp1, tmp2, tmp3;
    vector<Bot> r;
    vector<pair<int, int>> b;
    cin >> N >> M >> B;
    cin >> gx >> gy;
    rep(i, M){
        cin >> tmp1 >> tmp2 >> tmp3;
        r.push_back(Bot(tmp1, tmp2, tmp3));
    }
    rep(i, B){
        cin >> tmp1 >> tmp2;
        b.push_back(make_pair(tmp1, tmp2));
    }

    vector<int> g[40][40];
    rep(y, N){
        rep(x, N){
            if()
        }
    }
    return 0;
}