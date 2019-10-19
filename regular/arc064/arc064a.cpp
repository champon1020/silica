#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, s, e) for(int i=s; i>=e; i--)
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
template<typename T> void vdebug(vector<T> v){ for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int keta(ll num){ int k=0; while(num>0){ num/=10; k++; } return k; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


ll a[100010], diff[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    rep(i, n){
        cin >> a[i];
    }

    rep(i, n-1){
        diff[i] = (a[i+1]+a[i])-x;
    }

    ll res = 0;
    reps(i, 1, n-1){
        if(diff[i] > 0){
            if(diff[i-1] > 0 && a[i] > 0){
                while(a[i] > 0 && diff[i] > 0 && diff[i-1] > 0){
                    //cout << a[i] << " " << diff[i] << " " << diff[i-1] << endl;
                    diff[i]--;
                    diff[i-1]--;
                    a[i]--;
                    res++;
                }
            }
        }
    }

    rep(i, n-1){
        if(diff[i] > 0 && a[i] > 0){
            while(a[i] > 0 || diff[i] > 0){
                diff[i]--;
                diff[i+1]--;
                a[i]--;
                res++;
            }
        }
    }

    if(diff[n-2] > 0){
        while(diff[n-2] > 0){
            diff[n-2]--;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
