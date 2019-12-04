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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmpa;
    vector<int> a;
    cin >> n;

    rep(i, n){
        cin >> tmpa;
        a.push_back(tmpa);
    }

    sort(a.begin(), a.end());
    ll mod = 1e9+7;
    ll res = 1;
    if(n%2 == 0){
        ll marker = 1;
        for(int i=0; i<n-1; i+=2){
            if(a[i]==marker && a[i+1]==marker) marker+=2;
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        rep(i, n/2){
            res *= 2;
            res %= mod;
        }
    }else{
        ll marker = 2;
        if(a[0] != 0){
            cout << 0 << endl;
            return 0;
        }
        for(int i=1; i<n-1; i+=2){
            if(a[i]==marker && a[i+1]==marker) marker+=2;
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        rep(i, (n-1)/2){
            res *= 2;
            res %= mod;
        }
    }

    cout << res << endl;

    return 0;
}