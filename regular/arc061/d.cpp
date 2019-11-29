#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
#define reps(i, s, e) for(int i=s; i<=e; i++)
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

    ll h, w, a, b;
    int n;
    map<pair<ll, ll>, int> ab;
    ll cnt[100010];

    int delx[] = {0, -1, -2, 0, 0, -1, -1, -2, -2};
    int dely[] = {0, 0, 0, -1, -2, -1, -2, -1, -2};

    int cntit = 0;

    cin >> h >> w >> n;
    rep(i, n){
        cin >> a >> b;
        rep(i, 9){
            if(a + dely[i] <= 0 || h-2 < a + dely[i] || b + delx[i] <= 0 || w-2 < b + delx[i]) continue;
            ab[make_pair(a + dely[i], b + delx[i])]++;
            //cout << a << " " << b << " " << a + dely[i] << " " << b + delx[i] << endl;
        }
    }
    //cout << endl;
    //for(auto abb : ab) cout << abb.first << " " << abb.second << endl;

    ll res[10];
    rep(i, 10){
        res[i] = 0;
    }

    for(auto m : ab){
        res[m.second]++;
    }

    ll sum = 0;
    rep(i, 10){
        sum += res[i];
    }

    rep(i, 10){
        if(i == 0 && (h-2)*(w-2) - sum > 0){
            cout << (h-2)*(w-2) - sum << endl;
        }else{
            cout << res[i] << endl;
        }
    }

    return 0;
}
