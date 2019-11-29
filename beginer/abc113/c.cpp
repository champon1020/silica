#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repr(i, n) for(int i=n; i>=0; i--)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define inf 1e10
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
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
template<typename T> T arrdebug(T arr[], int n){ rep(i, n){ cout << arr[i] << " "; } cout << endl; }
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


vector<ll> v[100001];

int keta(ll num){
    int k = 0;
    while(num > 0){
        num /= 10;
        k++;
    }
    return k;
}

string addzero(ll num){
    string key = "";
    rep(i, 12-keta(num)){
        key += "0";
    }
    key += to_string(num);
    return key;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    ll p[100001];
    ll y[100001];
    cin >> n >> m;
    rep(i, m){
        cin >> p[i] >> y[i];
        v[p[i]].push_back(y[i]);
    }

    rep(i, n){
        vsort(v[i+1]);
    }

    rep(i, m){
        auto it = lower_bound(v[p[i]].begin(), v[p[i]].end(), y[i]);
        ll keynum = p[i]*1e6 + distance(v[p[i]].begin(), it) + 1;
        cout << addzero(keynum) << endl;
    }
    
  	return 0;
}